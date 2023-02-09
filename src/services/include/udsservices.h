#include "enums.h"
#include "diagnosticsessioncontrol.h"
#include "communicationcontrol.h"
#include "cleardiagnosticinformation.h"

namespace udsNames {

static const int answerSuppress = 0x80;

static QString DiagnosticSessionControl = QVariant::fromValue(Enums::ServiceTypes::DiagnosticSessionControl).toString();
static QString CommunicationControl = QVariant::fromValue(Enums::ServiceTypes::CommunicationControl).toString();
static QString ClearDiagnosticInformation = QVariant::fromValue(Enums::ServiceTypes::ClearDiagnosticInformation).toString();

}
