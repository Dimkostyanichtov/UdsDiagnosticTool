#ifndef RESULTMODEL_H
#define RESULTMODEL_H

#include <QString>

class resultModel
{
public:
    resultModel(QString time, QString name, QString data);
    virtual ~resultModel();
    QString getTimestamp();
    QString getServiceName();
    QString getAnswer();

private:
    QString timestamp;
    QString serviceName;
    QString answer;
};

#endif // RESULTMODEL_H
