#include "include/connectionupdater.h"

connectionUpdater::connectionUpdater(MainWindow* owner, connectCanDialog* sender)
    : owner(owner)
    , sender(sender)
{}

connectionUpdater::~connectionUpdater() {}

void connectionUpdater::run()
{
    emit requestUpdateConnections();
    while(continueUpdating) {
        QThread::msleep(timeout);
        if (deviceCount != (owner->getDevice()->getAvailableDevices(sender->getDriver())).count()) {
            deviceCount = (owner->getDevice()->getAvailableDevices(sender->getDriver())).count();
            emit requestUpdateConnections();
        }
    }
}

void connectionUpdater::onStopUpdating()
{
    continueUpdating = false;
}
