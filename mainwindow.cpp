#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QUrl>
#include <QDesktopServices>

#include "src/connection/include/connectcandialog.h"

using service_types = Enums::ServiceTypes;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , services(new QMap<QString, udsService*>)
    , sequence(new Sequence(this))
    , connected(false)
    , settings(new QSettings("mysoft", "udsdiagnostictool"))
{
    ui->setupUi(this);
    ui->menubar->hide();
    ui->serviceTableView->horizontalHeader()->setFont(QFont("Calibri", 14));
    ui->serviceTableView->setModel(sequence);

    //ui->restartSpinBox->setValue(settings->value("test").value<int>());

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

    ui->serviceComboBox->addItems(services->keys());
}

void MainWindow::resizeEvent(QResizeEvent* event)
{
   QMainWindow::resizeEvent(event);
   ui->serviceTableView->horizontalHeader()->resizeSection(0, ui->serviceTableView->width()/2);
}

MainWindow::~MainWindow()
{
    //settings->setValue("test", ui->restartSpinBox->value());
    delete ui;
}

void MainWindow::setConnect(bool connect)
{
    connected = connect;
}

bool MainWindow::connect() const
{
    return connected;
}

QList<QWidget *> *MainWindow::getCurrentWidgets(QString name)
{
    udsService* service = services->value(name);
    return service->getWidgets();
}

void MainWindow::on_exit_triggered()
{
    delete services;
    settings->setValue("test", ui->restartSpinBox->value());
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
    for(auto *widget : ui->centralwidget->findChildren<QWidget *>())
            widget->setEnabled(false);

    //TODO: processing

    for(auto *widget : ui->centralwidget->findChildren<QWidget *>())
            widget->setEnabled(true);
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
   QModelIndex index = ui->serviceTableView->selectionModel()->currentIndex();
   if (index.isValid())
       sequence->deleteService(index);
   else
   {
       if (sequence->rowCount() != 0)
       {
           index = ui->serviceTableView->selectionModel()->model()->index(ui->serviceTableView->model()->rowCount() - 1, 0);
           sequence->deleteService(index);
       }
   }
}

void MainWindow::on_connectSerialBus_triggered()
{
    if (connect()) {
        ui->connectSerialBus->setIcon(QIcon(":/icons/connect.png"));
        setConnect(false);
    } else {
        connectCanDialog* candialog = new connectCanDialog();
        candialog->show();

        ui->connectSerialBus->setIcon(QIcon(":/icons/disconnect.png"));
        setConnect(true);
    }
}

void MainWindow::on_clearServiceListPushButton_clicked()
{
    sequence->clearSequence();
}

