#ifndef SERVICEFACTORY_H
#define SERVICEFACTORY_H

#include <QString>
#include <QMap>

#include "udsservice.h"

class serviceCreator
{
public:
    serviceCreator();
    virtual ~serviceCreator();

    virtual udsService* createService() const = 0;
};

template <class C>
class udsServiceCreator : serviceCreator
{
public :
    udsServiceCreator();
    virtual ~udsServiceCreator();

    virtual udsService* createUdsService() const;
};

class serviceFactory
{
protected:
    typedef QMap<QString, udsService*> ServiceMap;
    ServiceMap serviceMap;

public:
    serviceFactory();
    virtual ~serviceFactory();

    template<class C>
    void addService(const QString&);

};

#endif // SERVICEFACTORY_H
