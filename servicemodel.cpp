#include "servicemodel.h"

serviceModel::serviceModel(QString name, QString data)
    : name(name)
    , data(data)
{}

QString serviceModel::getName() const
{
    return name;
}

QString serviceModel::getData() const
{
    return data;
}
