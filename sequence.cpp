#include "sequence.h"

Sequence::Sequence(QObject *parent) : QAbstractTableModel(parent) {
    services = new QList<serviceModel>();
}

int Sequence::columnCount(const QModelIndex &parent) const
{
    return 2;
}

int Sequence::rowCount(const QModelIndex &role) const
{
    return services->count();
}

QVariant Sequence::data(const QModelIndex &index, int role) const
{
    if (index.isValid() && role == Qt::DisplayRole)
        return getData(index.row(), index.column());
    return QVariant();
}

QVariant Sequence::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (role != Qt::DisplayRole)
        return QVariant();
    if (orientation == Qt::Vertical)
        return QVariant(section + 1);
    else {
        switch (section) {
        case 0:
            return QVariant("Service name");
        case 1:
            return QVariant("CAN message");
        default:
            return QVariant();
        }
    }
}

Qt::ItemFlags Sequence::flags(const QModelIndex &index) const
{
    return Qt::ItemIsSelectable | Qt::ItemIsEnabled;
}

void Sequence::addService(serviceModel &newService)
{
    beginInsertRows(QModelIndex(), services->size(), services->size());
    services->append(newService);
    endInsertRows();
}

void Sequence::insertService(serviceModel &newService, int index)
{
    beginInsertRows(QModelIndex(), services->size(), services->size());
    services->insert(index, newService);
    endInsertRows();
}

void Sequence::deleteService(const QModelIndex &index)
{
    beginRemoveRows(QModelIndex(), index.row(), index.row());
    services->removeAt(index.row());
    endRemoveRows();
}

serviceModel &Sequence::getService(const QModelIndex &index) const
{
    return (*services)[index.row()];
}

QVariant Sequence::getData(int num, int position) const
{
    switch (position) {
    case 0:
        return QVariant(services->at(num).getName());
    case 1:
        return QVariant(services->at(num).getData());
    default:
        return QVariant();
    }
}

