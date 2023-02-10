#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include "src/services/include/udsconstants.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , services(new QMap<QString, udsService*>)
{
    ui->setupUi(this);
    ui->menubar->hide();

    QString DiagnosticSessionControl = enumToString(Enums::ServiceTypes::DiagnosticSessionControl);
    QString CommunicationControl = enumToString(Enums::ServiceTypes::CommunicationControl);
    QString ClearDiagnosticInformation = enumToString(Enums::ServiceTypes::ClearDiagnosticInformation);

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

