#include "mainwindow.h"
#include "./ui_mainwindow.h"

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
    close();
}


void MainWindow::on_serviceComboBox_currentIndexChanged(int index)
{
    QList<QWidget*>* widgets = getCurrentWidgets(ui->serviceComboBox->currentText());
    for (QWidget* w : *widgets)
        ui->serviceVerticalLayout->addWidget(w);
}
