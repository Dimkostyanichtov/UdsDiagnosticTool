#include "include/devicereader.h"
#include "../../types.h"
#include "PCANBasic.h"

deviceReader::deviceReader() {}

deviceReader::~deviceReader() {}

QStringList deviceReader::getAvailableDevices(QString driver)
{
    QStringList result;

    if ((driver == "PEAK") || (driver == "PEAK_FD"))
    {
        int iBuffer;
        TPCANStatus stsResult;
        QMap<QString,ushort> pcan = PCanUsb;
        foreach (int value, pcan){
            stsResult = CAN_GetValue(value, PCAN_CHANNEL_CONDITION, (void*)&iBuffer, sizeof(iBuffer));
            if (((stsResult) == PCAN_ERROR_OK) && ((iBuffer & PCAN_CHANNEL_AVAILABLE) == PCAN_CHANNEL_AVAILABLE)) {
                result.append(pcan.key(value));
            }
        }
        return result;
    }
    else if (driver == "VSCOM")
    {

    }
    else if (driver == "SocketCAN")
    {
        QString errorString1;
        QStringList result;
    #ifdef Q_OS_WIN
        QString plugins = "peakcan";
    #endif
    #ifdef Q_OS_LINUX
        QString plugins = "socketcan";
    #endif
        foreach(const QCanBusDeviceInfo info, QCanBus::instance()->availableDevices(plugins, &errorString1))
        {
            if (errorString1.isEmpty()) result.append(info.name());
        }
        return result;
    }

    return result;
}

int deviceReader::connectDevice(QString dev)
{
    QString errorString;
    if(device){
        device->disconnectDevice();
        delete device;
    }
#ifdef Q_OS_WIN
    device = QCanBus::instance()->createDevice("peakcan", dev, &errorString);
#endif
#ifdef Q_OS_LINUX
    device = QCanBus::instance()->createDevice("socketcan", dev, &errorString);
#endif
    if (!device || !device->connectDevice()) return -1;
    return 0;
}

int deviceReader::connectDevice(QString adress, ushort port)
{
    return -1;
}

int deviceReader::connectDevice(QString dev, QString speed)
{
    TPCANStatus result;
    pcanDevice = PCanUsb.value(dev);
    result = CAN_Initialize(pcanDevice, PCanSpeed.value(speed), 0, 0x100, 0x3);
    return result;
}

void deviceReader::disconnectDevice()
{
    if (pcanDevice != 0)
        CAN_Uninitialize(pcanDevice);
    if(device)
        disconnect(device, &QCanBusDevice::framesReceived, this, &deviceReader::sendFramesToParser);
}

void deviceReader::sendFramesToParser()
{

}
