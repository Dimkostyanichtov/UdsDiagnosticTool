#ifndef SERVICEMODEL_H
#define SERVICEMODEL_H

#include <QString>
#include <QVector>

class serviceModel
{
public:
    serviceModel(QString name, QString data);

    QString getName() const;
    QString getData() const;

private:
    QString name;
    QString data;
};

#endif // SERVICEMODEL_H
