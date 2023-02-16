#include "include/connectionupdater.h"

connectionUpdater::connectionUpdater(connectCanDialog* dialog)
    : owner(dialog)
{}

connectionUpdater::~connectionUpdater() {}

void connectionUpdater::run()
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

void connectionUpdater::onStopUpdating()
{
    continueUpdating = false;
}
