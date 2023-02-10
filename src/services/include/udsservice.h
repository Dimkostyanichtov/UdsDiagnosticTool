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

#include "udsconstants.h"
#include "enums.h"

class udsService : public QObject
{
    Q_OBJECT
protected:
    QList<QWidget*>* widgets {};

public:
    udsService() {}
    virtual ~udsService() { delete[] widgets; }
    virtual QList<int> *request() = 0;
    QList<QWidget*>* getWidgets() { return widgets; }
};

#endif // UDSSERVICE_H
