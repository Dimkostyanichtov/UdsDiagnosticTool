#ifndef SEQUENCE_H
#define SEQUENCE_H

#include <QAbstractTableModel>

#include "servicemodel.h"

class Sequence : public QAbstractTableModel
{
public:
    Sequence(QObject  *parent);
    int columnCount(const QModelIndex &parent = QModelIndex()) const;
    int rowCount(const QModelIndex &role = QModelIndex()) const;
    QVariant data(const QModelIndex  &index, int role = Qt ::DisplayRole) const;
    QVariant  headerData ( int section, Qt ::Orientation orientation, int role = Qt ::DisplayRole ) const;
    Qt ::ItemFlags flags (const QModelIndex  & index) const;
    void addService(serviceModel &newService);
    void insertService(serviceModel &newService, int index);
    void deleteService(const QModelIndex &index);
    serviceModel& getService(const QModelIndex &index) const;

private:
    QList<serviceModel> *services;
    QVariant getData(int num, int position) const;
};

#endif // SEQUENCE_H
