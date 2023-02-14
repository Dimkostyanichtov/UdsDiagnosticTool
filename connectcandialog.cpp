#include "connectcandialog.h"
#include "ui_connectcandialog.h"

connectCanDialog::connectCanDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::connectCanDialog)
{
    ui->setupUi(this);
}

connectCanDialog::~connectCanDialog()
{
    delete ui;
}

void connectCanDialog::onUpdate()
{

}
