#include "include/devicereader.h"

#include <QCanBus>

deviceReader::deviceReader() {}

deviceReader::~deviceReader() {}

QStringList deviceReader::getAvailableDevices(QString driver)
{
    QStringList result;

    if ((driver == "PEAK") || (driver == "PEAK_FD"))
    {
        QString errorString1;
    #ifdef Q_OS_WIN
        QString plugins = "peakcan";
    #endif
    #ifdef Q_OS_LINUX
        QString plugins = "socketcan";
    #endif
        foreach(const QCanBusDeviceInfo info, QCanBus::instance()->availableDevices(plugins, &errorString1))
            if (errorString1.isEmpty()) result.append(info.name());
    }
    else if (driver == "VSCOM")
    {

    }
    else if (driver == "SocketCAN")
    {

    }

    return result;
}

int deviceReader::connectDevice(QString dev)
{
    return -1;
}

int deviceReader::connectDevice(QString adress, ushort port)
{
    return -1;
}

int deviceReader::connectDevice(QString dev, QString speed)
{
    return -1;
}

int deviceReader::disconnectDevice()
{
    return -1;
}
