#ifndef SERVICEFACTORY_H
#define SERVICEFACTORY_H

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
    typedef QMap<QString, serviceCreator*> ServiceMap;
    ServiceMap serviceMap;
    typedef QMap<QString, serviceCreator*> RoutineMap;
    ServiceMap routineMap;

public:
    serviceFactory() {}
    virtual ~serviceFactory() {}

    template <class C>
    void addService(const QString& id)
    {
        if (serviceMap.find(id) == serviceMap.end())
            serviceMap[id] = new udsServiceCreator<C>();
    }

    udsService *create(const QString& id)
    {
        typename ServiceMap::iterator it = serviceMap.find(id);
        if (it != serviceMap.end())
            return it.value()->createService();
        return 0;
    }
};

#endif // SERVICEFACTORY_H
