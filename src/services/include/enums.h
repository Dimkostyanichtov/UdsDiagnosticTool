#ifndef ENUMS_H
#define ENUMS_H

#include "qobjectdefs.h"
#include <QMetaEnum>

class Enums
{
    Q_GADGET
public:
    enum MessageTypes: int
    {
        SINGLE = 0,
        FIRST = 1,
        CONSECUTIVE = 2,
        FLOW = 3,
        ERROR = 4
    };
    Q_ENUM(MessageTypes);

    enum SessionTypes: int
    {
        Default = 0x01,
        Programming = 0x02,
        Extended = 0x03
    };
    Q_ENUM(SessionTypes);

    enum ServiceTypes: int
    {
        DiagnosticSessionControl = 0x10,
        ECUReset = 0x11,
        SecurityAccess = 0x27,
        CommunicationControl = 0x28,
        TesterPresent = 0x3E,
        AccessTimingParameter = 0x83,
        SecuredDataTransmission = 0x84,
        ResponseOnEvent = 0x86,
        WriteDataByIdentifier = 0x2E,
        LinkControl = 0x87,
        ReadDataByIdentifier = 0x22,
        ReadMemoryByAddress = 0x23,
        ReadScalingDataByIdentifier = 0x2A,
        DynamicallyDefineDataIdentifier = 0x2C,
        WriteMemoryByAddress = 0x3D,
        ClearDiagnosticInformation = 0x14,
        ReadDTCInformation = 0x19,
        ControlDTCSetting = 0x85,
        InputOutputControlByIdentifier = 0x2F,
        RoutineControl = 0x31,
        RequestDownload = 0x34,
        RequestUpload = 0x35,
        TransferData = 0x36,
        RequestTransferExit = 0x37,
        RequestFileTransfer = 0x38
    };
    Q_ENUM(ServiceTypes);

    enum ServiceAnswers : int
    {
        DiagnosticSessionControlAnswer = 0x50,
        ResetAnswer = 0x51,
        ClearDiagnosticInformationAnswer = 0x54,
        ReadDTCInformationAnswer = 0x59,
        ReadDataByIDAnswer= 0x62,
        SecurityAccessAnswer = 0x67,
        CommunicationControlAnswer = 0x68,
        RoutineControlAnswer = 0x71,
        RequestDownloadAnswer = 0x74,
        RequestUploadAnswer = 0x75,
        TransferDataAnswer= 0x76,
        RequestTransferExitAnswer = 0x77,
        RequestFileTransferAnswer = 0x78,
        WriteDataByIDAnswer= 0x6E,
        InputOutputControlAnswer = 0x6F,
        TesterPresentAnswer = 0x7E,
        ControlDTCSettingsAnswer = 0xC5
    };
    Q_ENUM(ServiceAnswers);

};

#endif // ENUMS_H
