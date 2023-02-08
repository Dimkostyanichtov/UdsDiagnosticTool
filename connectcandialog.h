#ifndef CONNECTCANDIALOG_H
#define CONNECTCANDIALOG_H

#include <QDialog>

namespace Ui {
class connectcandialog;
}

class connectcandialog : public QDialog
{
    Q_OBJECT

public:
    explicit connectcandialog(QWidget *parent = nullptr);
    ~connectcandialog();

private:
    Ui::connectcandialog *ui;
};

#endif // CONNECTCANDIALOG_H
