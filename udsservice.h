#ifndef UDSSERVICE_H
#define UDSSERVICE_H

#include <QByteArrayList>

class udsService
{
public:
    udsService() {};
    virtual ~udsService() {};

    virtual QByteArrayList request() = 0;
};

#endif // UDSSERVICE_H
