#ifndef UDSSERVICE_H
#define UDSSERVICE_H

#include <QByteArrayList>
#include <QWidget>
#include <QLabel>
#include <QComboBox>
#include <QLineEdit>
#include <QString>
#include <QMap>
#include <QObject>
#include <QRegExp>

class udsService : public QObject
{
    Q_OBJECT
protected:
    QList<QWidget*> widgets {};

public:
    udsService();
    virtual ~udsService();
    virtual QList<int> *request() = 0;
    QList<QWidget*> getWidgets();
};

#endif // UDSSERVICE_H
