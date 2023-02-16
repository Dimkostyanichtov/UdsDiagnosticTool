#ifndef CONNECTIONUPDATER_H
#define CONNECTIONUPDATER_H

#include <QThread>

#include "../../../mainwindow.h"
#include "connectcandialog.h"

class connectionUpdater : public QThread
{
    Q_OBJECT
    friend class MainWindow;

private:
    connectCanDialog *sender;
    MainWindow *owner;
    bool continueUpdating = true;
    const int timeout = 100;
    uint deviceCount = 0;

public:
    connectionUpdater(MainWindow* owner, connectCanDialog* sender);
    virtual ~connectionUpdater();

    void run();

signals:
    void requestUpdateConnections();

public slots:
    void onStopUpdating();

};

#endif // CONNECTIONUPDATER_H
