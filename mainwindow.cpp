#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include "servicefactory.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->menubar->hide();

    serviceFactory services;
}

MainWindow::~MainWindow()
{
    delete ui;
}

