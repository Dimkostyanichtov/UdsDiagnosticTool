#include "resultmodel.h"

resultModel::resultModel(QString time, QString name, QString data) :
    timestamp(time)
    ,serviceName(name)
    ,answer(data)
{}

resultModel::~resultModel() {}

QString resultModel::getTimestamp()
{
    return timestamp;
}

QString resultModel::getServiceName()
{
    return serviceName;
}

QString resultModel::getAnswer()
{
    return answer;
}


