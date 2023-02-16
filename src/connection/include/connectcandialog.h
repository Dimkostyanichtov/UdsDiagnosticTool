#ifndef CONNECTCANDIALOG_H
#define CONNECTCANDIALOG_H

#include <QDialog>

namespace Ui {
class connectCanDialog;
}

class connectCanDialog : public QDialog
{
    Q_OBJECT

public:
    explicit connectCanDialog(QWidget *parent = nullptr);
    ~connectCanDialog();

public slots:
    void onUpdate();

private slots:
    void on_connectPushButton_clicked();

    void on_checkBox_stateChanged(int arg1);

private:
    Ui::connectCanDialog *ui;
    QStringList canDrivers { "PEAK", "PEAK_FD", "VSCOM", "SocketCAN" };

};

#endif // CONNECTCANDIALOG_H
