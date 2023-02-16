#include "include/connectcandialog.h"
#include "../../ui_connectcandialog.h"

#include "include/connectionupdater.h"

connectCanDialog::connectCanDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::connectCanDialog)
{
    ui->setupUi(this);
    //ui->bitrateComboBox->addItems()
    ui->driverComboBox->addItems(canDrivers);

    setWindowFlags(Qt::Dialog | Qt::MSWindowsFixedSizeDialogHint);
    setWindowFlags(windowFlags() & ~Qt::WindowContextHelpButtonHint);

    ui->txidLineEdit->setValidator(new QRegExpValidator(QRegExp("[0-9a-fA-F]{0,6}")));
    ui->rxidLineEdit->setValidator(new QRegExpValidator(QRegExp("[0-9a-fA-F]{0,6}")));

    connectionUpdater* updater = new connectionUpdater(this);
    connect(updater, &connectionUpdater::requestUpdateConnections, this, &connectCanDialog::onUpdate, Qt::QueuedConnection);
    updater->start();
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
        ui->channelComboBox->addItem("Channels not found");
        for (QWidget *widget : ui->connectGroupBox->findChildren<QWidget*>()) {
            if (widget->isEnabled()) widget->setEnabled(false);
            else return;
        }
    }
}

void connectCanDialog::on_connectPushButton_clicked()
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


void connectCanDialog::on_checkBox_stateChanged(int arg1)
{
    if (arg1 == 2)
        ui->canfdGroupBox->setEnabled(true);
    else
        ui->canfdGroupBox->setEnabled(false);
}

