#ifndef SERVICEFACTORY_H
#define SERVICEFACTORY_H

#include <QString>
#include <QMap>

#include "udsservice.h"

class serviceCreator
{
public:
    serviceCreator() {}
    virtual ~serviceCreator() {}

    virtual udsService* createService() const = 0;
};

template <class C>
class udsServiceCreator : public serviceCreator
{
public :
    udsServiceCreator() {}
    virtual ~udsServiceCreator() {}

    udsService* createService() const override { return new C(); }
};

class serviceFactory
{
protected:
    typedef QMap<std::string, serviceCreator*> ServiceMap;
    ServiceMap serviceMap;

public:
    serviceFactory() {}
    virtual ~serviceFactory() {}

    template <class C>
    void addService(const std::string& id) {
        if (serviceMap.find(id) == serviceMap.end())
            serviceMap[id] = new udsServiceCreator<C>();
    }

};

#endif // SERVICEFACTORY_H
