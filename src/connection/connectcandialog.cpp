#include "include/connectcandialog.h"
#include "../../ui_connectcandialog.h"

#include <QMessageBox>

connectCanDialog::connectCanDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::connectCanDialog)
{
    ui->setupUi(this);
    //ui->bitrateComboBox->addItems()
    ui->driverComboBox->addItems(canDrivers);

    setWindowFlags(Qt::Dialog | Qt::MSWindowsFixedSizeDialogHint);
    setWindowFlags(windowFlags() & ~Qt::WindowContextHelpButtonHint);

    connectUpdater = new ::connectUpdater(ui);
    connect(connectUpdater, SIGNAL(requestUpdateConnections()), this, SLOT(onUpdate()), Qt::QueuedConnection);
    connectUpdater->start();
}

connectCanDialog::~connectCanDialog()
{
    delete ui;
}

void connectCanDialog::onUpdate()
{
    ui->channelComboBox->clear();
    //ui->channelComboBox->addItems(owner->getDevice()->getAvailableDevices(ui->driverComboBox->currentText()));
    if (ui->channelComboBox->count() != 0) {
        for (QWidget *widget : ui->connectGroupBox->findChildren<QWidget*>()) {
            if (!widget->isEnabled()) widget->setEnabled(true);
            else return;
        }
    } else {
        ui->channelComboBox->addItem("Каналы не найдены");
        for (QWidget *widget : ui->connectGroupBox->findChildren<QWidget*>()) {
            if (widget->isEnabled()) widget->setEnabled(false);
            else return;
        }
    }
}

void connectCanDialog::on_canfdCheckBox_stateChanged(int arg1)
{
    if (arg1 == 2)
        ui->canfdGroupBox->setEnabled(true);
    else
        ui->canfdGroupBox->setEnabled(false);
}

connectUpdater::connectUpdater(Ui::connectCanDialog *sender) : sender(sender) {}

connectUpdater::~connectUpdater() {}

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

void connectUpdater::on_connectPushButton_clicked()
{
    //ConnectSerialBus* serialDevice = owner->getDevice();
    //if (!serialDevice->connectDevice(ui->driverComboBox->currentText(), ui->chanComboBox->currentText(), ui->bitRateComboBox->currentText())) {
    //    QMessageBox::warning(this, tr("Внимание!"), tr("Ошибка подключения!"),  QMessageBox::Cancel);
    //}
    //else {
    //    serialDevice->setConnected(true);
    //    emit connectCanBus();
    //    connectUpdater->onStopUpdating();
    //    close();
    //}
}
