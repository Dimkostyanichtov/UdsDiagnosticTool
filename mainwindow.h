#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "src/services/include/uds.h"
#include "sequence.h"
#include "src/connection/include/devicereader.h"
#include <QSettings>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT
    Q_PROPERTY(bool connect READ connect WRITE setConnect)

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void resizeEvent(QResizeEvent* event);

    void setConnect(bool connect);
    bool connect() const;

    deviceReader* getDevice();
    void setDevice (deviceReader*);

    QList<QWidget*>* getCurrentWidgets(QString);

private slots:
    void on_exit_triggered();

    void on_serviceComboBox_currentIndexChanged(int index);

    void on_linkPushButton_clicked();

    void on_run_triggered();

    void on_addServicePushButton_clicked();

    void on_deleteServicePushButton_clicked();

    void on_connectSerialBus_triggered();

    void on_clearServiceListPushButton_clicked();

    void on_logResultsPushButtonLog_clicked();

private:
    QSettings* settings;
    Ui::MainWindow *ui;
    QMap<QString, udsService*> *services;
    Sequence *sequence;
    bool connected;
    deviceReader* device;
};

#endif // MAINWINDOW_H
