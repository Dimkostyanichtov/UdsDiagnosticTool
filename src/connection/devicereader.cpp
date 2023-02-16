#include "include/devicereader.h"

#include <QCanBus>
#include <PCANBasic.h>
#include "../../types.h"

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
    TPCANStatus result;
    pcanDevice = PCanUsb.value(dev);
    result = CAN_Initialize(pcanDevice, PCanSpeed.value(speed), 0, 0x100, 0x3);
    return result;
}

void deviceReader::disconnectDevice()
{
    if (pcanDevice != 0)
        CAN_Uninitialize(pcanDevice);
}
