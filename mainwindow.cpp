#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include "qglobal.h"
#include "src/connection/include/connectcandialog.h"

#include <QUrl>
#include <QDesktopServices>
#include <functional>
#include <QJsonObject>
#include <QFileDialog>
#include <QMessageBox>

using service_types = Enums::ServiceTypes;

struct SaveFormat {
    QString serviceName;
    QString canMessage;
    SaveFormat(QString name, QString msg) : serviceName(name), canMessage(msg) {}
};

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , services(new QMap<QString, udsService*>)
    , sequence(new Sequence(this))
    , connected(false)
    , settings(new QSettings("mysoft", "udsdiagnostictool"))
    , device(new deviceReader)
{
    ui->setupUi(this);
    ui->menubar->hide();
    ui->serviceTableView->horizontalHeader()->setFont(QFont("Calibri", 14));
    ui->serviceTableView->setModel(sequence);

    ui->delaySpinBox->setValue(settings->value("delaySpinBox").value<int>());
    ui->restartSpinBox->setValue(settings->value("restartSpinBox").value<int>());

    QString DiagnosticSessionControl = enumToString(service_types::DiagnosticSessionControl);
    QString CommunicationControl = enumToString(service_types::CommunicationControl);
    QString ClearDiagnosticInformation = enumToString(service_types::ClearDiagnosticInformation);

    serviceFactory serviceCreator;
    serviceCreator.addService<diagnosticSessionControl>(DiagnosticSessionControl);
    serviceCreator.addService<communicationControl>(CommunicationControl);
    serviceCreator.addService<clearDiagnosticInformation>(ClearDiagnosticInformation);

    services->insert(DiagnosticSessionControl, serviceCreator.create(DiagnosticSessionControl));
    services->insert(CommunicationControl, serviceCreator.create(CommunicationControl));
    services->insert(ClearDiagnosticInformation, serviceCreator.create(ClearDiagnosticInformation));

    QObject::connect(&watcher,  &QFutureWatcher<void>::finished, this, &MainWindow::processFinished);
    QObject::connect(&watcher,  &QFutureWatcher<void>::progressRangeChanged, ui->progressBar, &QProgressBar::setRange);
    QObject::connect(&watcher, &QFutureWatcher<void>::progressValueChanged,  ui->progressBar, &QProgressBar::setValue);

    ui->serviceComboBox->addItems(services->keys());
}

void MainWindow::resizeEvent(QResizeEvent* event)
{
   QMainWindow::resizeEvent(event);
   ui->serviceTableView->horizontalHeader()->resizeSection(0, ui->serviceTableView->width()/2);
}

MainWindow::~MainWindow()
{
    settings->setValue("delaySpinBox", ui->restartSpinBox->value());
    settings->setValue("restartSpinBox", ui->restartSpinBox->value());
    delete ui;
}

void MainWindow::setConnect(bool connect)
{
    if (connect)
        ui->connectSerialBus->setIcon(QIcon(":/icons/disconnect.png"));
    else
        ui->connectSerialBus->setIcon(QIcon(":/icons/connect.png"));
    connected = connect;
}

bool MainWindow::connect() const
{
    return connected;
}

deviceReader *MainWindow::getDevice()
{
    return device;
}

void MainWindow::setDevice(deviceReader *dev)
{
    device = dev;
}

QList<QWidget*> *MainWindow::getCurrentWidgets(QString name)
{
    udsService* service = services->value(name);
    return service->getWidgets();
}

void MainWindow::on_exit_triggered()
{
    delete services;
    settings->setValue("delaySpinBox", ui->restartSpinBox->value());
    settings->setValue("restartSpinBox", ui->restartSpinBox->value());
    close();
}

void MainWindow::on_serviceComboBox_currentIndexChanged(int index)
{
    while (QLayoutItem* item = ui->serviceOptionsLayout->layout()->takeAt(0)) {
        delete item->widget();
        delete item;
    }
    ui->serviceOptionsLabel->setText(ui->serviceComboBox->currentText() + " options");
    QList<QWidget*>* widgets = getCurrentWidgets(ui->serviceComboBox->currentText());
    for (QWidget* w : *widgets)
        ui->serviceOptionsLayout->addWidget(w);
}

void MainWindow::on_linkPushButton_clicked()
{
    QDesktopServices::openUrl(QUrl("https://github.com/Dimkostyanichtov/UdsDiagnosticTool", QUrl::TolerantMode));
}

void MainWindow::on_run_triggered()
{
    if (sequence->rowCount() != 0) {
        QElapsedTimer timer;
        QList<QString> test;
        QList<QString> test2;

        for(auto *widget : ui->centralwidget->findChildren<QWidget *>())
            widget->setEnabled(false);
        this->setCursor(Qt::WaitCursor);

        QVector<QString> current_services;

        timer.start();

        foreach (serviceModel model, sequence->getModelList()) {
            current_services.append(model.getData());
        }

        std::function<void(const QVector<QString>&)> process = [&test](const QVector<QString>& model) {
            QThread::sleep(5);
            foreach(QString s, model)
                test.append(s + "test");
        };

        QFuture<void> future = QtConcurrent::run(process, current_services);

        watcher.setFuture(future);

        //test.append(watcher.result());

        //while(!watcher.future().isFinished()) {
        //    if (!test.empty()) {
        //        test2.append(test.first());
        //        test.removeFirst();
        //    }
        //}

        //watcher.waitForFinished();
    }
}

void MainWindow::on_addServicePushButton_clicked()
{
    udsService* currentService = *(services->find(ui->serviceComboBox->currentText()));
    serviceModel service(ui->serviceComboBox->currentText(), udsService::listToString(*currentService->request()));
    QModelIndex index = ui->serviceTableView->selectionModel()->currentIndex();
    if (index.isValid())
        sequence->insertService(service, index.row() + 1);
    else
        sequence->addService(service);
    ui->serviceTableView->verticalHeader()->resizeSections(QHeaderView::ResizeToContents);
}

void MainWindow::on_deleteServicePushButton_clicked()
{
    if (sequence->rowCount() != 0)
    {
        QList<QModelIndex> indexes;
        indexes.append(ui->serviceTableView->selectionModel()->selectedIndexes());
        if (!indexes.empty())
            sequence->deleteServices(indexes[0], indexes.count() - 1);
        else
        {
           QModelIndex index = ui->serviceTableView->selectionModel()->model()->index(ui->serviceTableView->model()->rowCount() - 1, 0);
           sequence->deleteService(index);
        }
    }
}

void MainWindow::on_connectSerialBus_triggered()
{
    if (connect()) {
        device->disconnectDevice();
        setConnect(false);
    } else {
        connectCanDialog* candialog = new connectCanDialog(this);
        candialog->show();
    }
}

void MainWindow::on_clearServiceListPushButton_clicked()
{
    sequence->clearSequence();
}

void MainWindow::on_logResultsPushButtonLog_clicked()
{

}

void MainWindow::processFinished()
{
    for(auto *widget : ui->centralwidget->findChildren<QWidget *>())
        widget->setEnabled(true);
    this->setCursor(Qt::ArrowCursor);
}


void MainWindow::on_saveTemplate_triggered()
{
    QString filename;
    QFileDialog dialog(this);
    dialog.setFileMode(QFileDialog::AnyFile);
    dialog.setViewMode(QFileDialog::Detail);
    filename = dialog.getSaveFileName(NULL, "Save file","","*.json");

    QFile file(filename);
    if(file.open( QIODevice::WriteOnly | QIODevice::Text | QIODevice::Truncate ))
    {
        QJsonDocument document;
        QJsonObject content;
        QList<serviceModel> services = sequence->getModelList();
        for(int i = 0; i < services.count(); ++i) {
            SaveFormat s = SaveFormat(services[i].getName(), services[i].getData());
            QJsonObject s_obj;
            s_obj.insert("name", s.serviceName);
            s_obj.insert("msg", s.canMessage);
            content.insert(QString::number(i), s_obj);
        }
        document.setObject( content );
        QByteArray bytes = document.toJson( QJsonDocument::Indented );
        QTextStream iStream( &file );
        iStream.setCodec( "utf-8" );
        iStream << bytes;
        file.close();
    }
}


void MainWindow::on_openTemplate_triggered()
{
    QString filename;
    QFileDialog dialog(this);
    dialog.setFileMode(QFileDialog::AnyFile);
    dialog.setViewMode(QFileDialog::Detail);
    filename = dialog.getOpenFileName(NULL, "Open file", "", "*json");

    QFile file(filename);
    if(file.open(QIODevice::ReadOnly)) {
        sequence->clearSequence();
        QByteArray bytes = file.readAll();
        file.close();

        QJsonParseError err;
        QJsonDocument document = QJsonDocument::fromJson(bytes, &err);
        if (err.error != QJsonParseError::NoError)
            QMessageBox::warning(this, tr("Attention!"), tr("Wrong format!"));
        else {
            if (document.isObject()) {
                QJsonObject jsonObj = document.object();
                QStringList services = jsonObj.keys();
                for (int i = 0; i < services.count(); ++i) {
                    if (jsonObj.contains(services[i])) {
                        QJsonObject s_obj = jsonObj.value(services[i]).toObject();
                        serviceModel service(s_obj.value("name").toString(), s_obj.take("msg").toString());
                        QModelIndex index = ui->serviceTableView->selectionModel()->currentIndex();
                        if (index.isValid())
                            sequence->insertService(service, index.row() + 1);
                        else
                            sequence->addService(service);
                        ui->serviceTableView->verticalHeader()->resizeSections(QHeaderView::ResizeToContents);
                    }
                    else {
                        QMessageBox::warning(this, tr("Attention!"), tr("Wrong format!"));
                        return;
                    }
                }
            }
            else
                QMessageBox::warning(this, tr("Attention!"), tr("Wrong format!"));
        }
    }
}


void MainWindow::on_cleanResultsPushButton_clicked()
{
    //ui->resultsListView->
}

