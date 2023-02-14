#ifndef CONNECTIONUPDATER_H
#define CONNECTIONUPDATER_H

#include <QThread>

#include "connectcandialog.h"


class connectionUpdater : public QThread
{
    Q_OBJECT

private:
    volatile bool update = true;
    connectCanDialog *owner;
    const uint timeout = 100;

public:
    connectionUpdater(connectCanDialog*);

    void run();
    void stop();

signals:
    void updateConnections();
};

#endif // CONNECTIONUPDATER_H
