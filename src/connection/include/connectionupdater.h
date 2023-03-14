#ifndef CONNECTIONUPDATER_H
#define CONNECTIONUPDATER_H

#include "../../../mainwindow.h"
#include "connectcandialog.h"

#include <QThread>

class connectionUpdater : public QThread
{
    Q_OBJECT
    friend class MainWindow;

private:
    connectCanDialog *sender;
    MainWindow *owner;
    bool continueUpdating = true;
    const int timeout = 100;
    QStringList devices;

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
