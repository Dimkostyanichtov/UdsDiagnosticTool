#include "connectcandialog.h"
#include "ui_connectcandialog.h"

connectcandialog::connectcandialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::connectcandialog)
{
    ui->setupUi(this);
}

connectcandialog::~connectcandialog()
{
    delete ui;
}
