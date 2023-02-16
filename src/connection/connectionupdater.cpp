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
        if (devices != (owner->getDevice()->getAvailableDevices(sender->getDriver()))) {
            emit requestUpdateConnections();
            devices = (owner->getDevice()->getAvailableDevices(sender->getDriver()));
        }
    }
}

void connectionUpdater::onStopUpdating()
{
    continueUpdating = false;
}
