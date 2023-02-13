#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QUrl>
#include <QDesktopServices>

using service_types = Enums::ServiceTypes;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , services(new QMap<QString, udsService*>)
{
    ui->setupUi(this);
    ui->menubar->hide();

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

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_exit_triggered()
{
    delete services;
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

    for(auto *widget : ui->centralwidget->findChildren<QWidget *>())
            widget->setEnabled(true);
}

