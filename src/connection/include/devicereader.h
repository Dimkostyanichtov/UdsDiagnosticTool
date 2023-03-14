#ifndef DEVICEREADER_H
#define DEVICEREADER_H

#include <QObject>
#include <QCanBus>

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
    void startReading();
    void disconnectDevice();

private slots:
    void sendFramesToParser();

private:
    ushort pcanDevice = 0;
    QCanBusDevice *device = nullptr;

};

#endif // DEVICEREADER_H
