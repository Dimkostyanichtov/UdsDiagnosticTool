#include "include/connectcandialog.h"
#include "../../ui_connectcandialog.h"

connectCanDialog::connectCanDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::connectCanDialog)
{
    ui->setupUi(this);

    //ui->bitrateComboBox->addItems()
    ui->driverComboBox->addItems(canDrivers);

    setWindowFlags(Qt::Dialog | Qt::MSWindowsFixedSizeDialogHint);
    setWindowFlags(windowFlags() & ~Qt::WindowContextHelpButtonHint);
}

connectCanDialog::~connectCanDialog()
{
    delete ui;
}

void connectCanDialog::onUpdate()
{

}

void connectCanDialog::on_canfdCheckBox_stateChanged(int arg1)
{
    if (arg1 == 2)
        ui->canfdGroupBox->setEnabled(true);
    else
        ui->canfdGroupBox->setEnabled(false);
}


connectUpdater::connectUpdater(Ui::connectCanDialog *sender)
{

}

connectUpdater::~connectUpdater()
{

}

void connectUpdater::run()
{
    emit requestUpdateConnections();
    while(continueUpdating) {
        QThread::msleep(timeout);
        //if (deviceCount != (owner->getDevice()->getAvailableDevices(sender->driverComboBox->currentText())).count()) {
        //    deviceCount = (owner->getDevice()->getAvailableDevices(sender->driverComboBox->currentText())).count();
        //    emit requestUpdateConnections();
        //}
    }
}

void connectUpdater::onStopUpdating()
{
    continueUpdating = false;
}
