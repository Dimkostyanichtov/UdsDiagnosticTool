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

private:
    Ui::connectCanDialog *ui;

    //enum Drivers {
    //    ""
    //};

public slots:
    void onUpdate();
};

#endif // CONNECTCANDIALOG_H
