#include "servicefactory.h"

serviceCreator::serviceCreator() {}

serviceCreator::~serviceCreator() {}

template<class C>
udsServiceCreator<C>::udsServiceCreator() {}

template<class C>
udsServiceCreator<C>::~udsServiceCreator() {}

serviceFactory::serviceFactory() {}

serviceFactory::~serviceFactory() {}

template<class C>
void serviceFactory::addService(const QString &id)
{
    typename ServiceMap::Iterator it = serviceMap.find(id);
    if (it == serviceMap.end())
        serviceMap[id] = new udsServiceCreator<C>();
}
