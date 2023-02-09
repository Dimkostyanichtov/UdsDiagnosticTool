#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include "servicefactory.h"
#include "diagnosticsessioncontrol.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->menubar->hide();

    serviceFactory services;
    services.addService<diagnosticSessionControl>("diagnosticSessionControl");
}

MainWindow::~MainWindow()
{
    delete ui;
}
