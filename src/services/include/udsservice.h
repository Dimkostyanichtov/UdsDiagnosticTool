#ifndef UDSSERVICE_H
#define UDSSERVICE_H

#include <QByteArrayList>
#include <QWidget>

class udsService
{
protected:
    QList<QWidget*> widgets {};

public:
    udsService() {}
    virtual ~udsService() {}
    virtual QByteArrayList *request() = 0;
    QList<QWidget*> getWidgets() { return widgets; }
};

#endif // UDSSERVICE_H
