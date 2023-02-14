#include "connectionupdater.h"

connectionUpdater::connectionUpdater(connectCanDialog *dialog)
    : owner(dialog)
{
    QObject::connect(this, &connectionUpdater::updateConnections, owner, &connectCanDialog::onUpdate);
}

void connectionUpdater::run()
{
    while(update)
    {
        if (false)
            emit updateConnections();
        QThread::sleep(timeout);
    }
}

void connectionUpdater::stop()
{
    update = false;
}
