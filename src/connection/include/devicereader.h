#ifndef DEVICEREADER_H
#define DEVICEREADER_H

#include <QObject>

class deviceReader: public QObject
{
    Q_OBJECT

public:
    deviceReader();
    virtual ~deviceReader();
    static QStringList getAvailableDevices(QString driver);
    int connectDevice(QString dev); //QCan
    int connectDevice(QString adress, ushort port); //Server
    int connectDevice(QString dev, QString speed); //Pcan
    int disconnectDevice();

private:

};

#endif // DEVICEREADER_H
