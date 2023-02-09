#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include "src/services/include/servicefactory.h"
#include "src/services/include/udsservices.h"

using namespace udsNames;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , services(new QMap<QString, udsService*>)
{
    ui->setupUi(this);
    ui->menubar->hide();

    serviceFactory serviceCreator;
    serviceCreator.addService<diagnosticSessionControl>(DiagnosticSessionControl);
    //serviceCreator.addService<communicationControl>(cc);
    //serviceCreator.addService<clearDiagnosticInformation>(cdi);

    services->insert(DiagnosticSessionControl, serviceCreator.create(DiagnosticSessionControl));
    //services->insert(dsc, serviceCreator.create(cc));
    //services->insert(dsc, serviceCreator.create(cdi));
}

MainWindow::~MainWindow()
{
    delete ui;
}
