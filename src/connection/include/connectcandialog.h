#ifndef CONNECTCANDIALOG_H
#define CONNECTCANDIALOG_H

#include <QDialog>
#include "../../mainwindow.h"

namespace Ui {
class connectCanDialog;
}

class connectCanDialog : public QDialog
{
    Q_OBJECT

public:
    connectCanDialog(MainWindow* owner, QWidget *parent = nullptr);
    ~connectCanDialog();

    QString getDriver();

public slots:
    void onUpdate();

signals:
    void requestStopUpdating();

private slots:
    void on_connectPushButton_clicked();

    void on_checkBox_stateChanged(int arg1);

    void on_txidLineEdit_textChanged(const QString &arg1);

    void on_rxidLineEdit_textChanged(const QString &arg1);

private:
    Ui::connectCanDialog *ui;
    QStringList canDrivers { "PEAK", "PEAK_FD", "VSCOM", "SocketCAN" };
    MainWindow* owner;

};

#endif // CONNECTCANDIALOG_H
