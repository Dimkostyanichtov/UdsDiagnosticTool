#include "include/connectcandialog.h"
#include "../../ui_connectcandialog.h"

#include "include/connectionupdater.h"

#include <QMessageBox>

connectCanDialog::connectCanDialog(MainWindow* owner, QWidget *parent)
    : owner(owner)
    , QDialog(parent)
    , ui(new Ui::connectCanDialog)
{
    ui->setupUi(this);
    //ui->bitrateComboBox->addItems()
    ui->driverComboBox->addItems(canDrivers);

    setWindowFlags(Qt::Dialog | Qt::MSWindowsFixedSizeDialogHint);
    setWindowFlags(windowFlags() & ~Qt::WindowContextHelpButtonHint);

    ui->txidLineEdit->setValidator(new QRegExpValidator(QRegExp("[0-9a-fA-F]{0,6}")));
    ui->rxidLineEdit->setValidator(new QRegExpValidator(QRegExp("[0-9a-fA-F]{0,6}")));

    ui->channelComboBox->addItem("Searchng...");

    connectionUpdater* updater = new connectionUpdater(owner, this);
    connect(updater, &connectionUpdater::requestUpdateConnections, this, &connectCanDialog::onUpdate, Qt::QueuedConnection);
    connect(this, &connectCanDialog::requestStopUpdating, updater, &connectionUpdater::onStopUpdating, Qt::QueuedConnection);
    updater->start();
}

connectCanDialog::~connectCanDialog()
{
    delete ui;
}

QString connectCanDialog::getDriver()
{
    return ui->driverComboBox->currentText();
}

void connectCanDialog::onUpdate()
{
    ui->channelComboBox->clear();
    ui->channelComboBox->addItems(owner->getDevice()->getAvailableDevices(ui->driverComboBox->currentText()));
    if (ui->channelComboBox->count() != 0) {
        ui->connectGroupBox->setEnabled(true);
    } else {
        ui->channelComboBox->addItem("Channels not found");
        ui->connectGroupBox->setEnabled(false);
    }
}

void connectCanDialog::on_connectPushButton_clicked()
{
    if ((ui->driverComboBox->currentText() == "PEAK") || (ui->driverComboBox->currentText() == "PEAK_FD"))
    {
        if (false) {//(!device->connectDevice(ui->driverComboBox->currentText(), ui->channelComboBox->currentText(), ui->bitRateComboBox->currentText())) {
            QMessageBox::warning(this, tr("Внимание!"), tr("Ошибка подключения!"),  QMessageBox::Cancel);
        }
        else
        {
            //owner->setDevice(device)
            owner->setConnect(true);
            emit requestStopUpdating();
            close();
        }
    }
    else if (ui->driverComboBox->currentText() == "SocketCAN")
    {

    }
}


void connectCanDialog::on_checkBox_stateChanged(int arg1)
{
    if (arg1 == 2)
        ui->canfdGroupBox->setEnabled(true);
    else
        ui->canfdGroupBox->setEnabled(false);
}


void connectCanDialog::on_txidLineEdit_textChanged(const QString &arg1)
{
    ui->txidLineEdit->setText(ui->txidLineEdit->text().toUpper());
}


void connectCanDialog::on_rxidLineEdit_textChanged(const QString &arg1)
{
    ui->rxidLineEdit->setText(ui->rxidLineEdit->text().toUpper());
}

