#ifndef CONNECTCANDIALOG_H
#define CONNECTCANDIALOG_H

#include <QDialog>
#include <QThread>

#include "../../../mainwindow.h"

namespace Ui {
class connectCanDialog;
}

class connectUpdater : public QThread
{
    Q_OBJECT

    friend class MainWindow;

private:
    Ui::connectCanDialog* sender;
    bool continueUpdating = true;
    const int timeout = 100;
    uint deviceCount = 0;

public:
    explicit connectUpdater(Ui::connectCanDialog *sender);
    virtual ~connectUpdater();

    void run();

signals:
    void requestUpdateConnections();

public slots:
    void onStopUpdating();
};

class connectCanDialog : public QDialog
{
    Q_OBJECT

public:
    explicit connectCanDialog(QWidget *parent = nullptr);
    ~connectCanDialog();

private:
    Ui::connectCanDialog *ui;
    QStringList canDrivers { "PEAK", "PEAK_FD", "VSCOM", "SocketCAN" };
    connectUpdater* connectUpdater;

public slots:
    void onUpdate();
private slots:
    void on_canfdCheckBox_stateChanged(int arg1);
};

#endif // CONNECTCANDIALOG_H
