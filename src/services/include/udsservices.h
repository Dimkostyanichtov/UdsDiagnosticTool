#include "enums.h"
#include "diagnosticsessioncontrol.h"
#include "communicationcontrol.h"
#include "cleardiagnosticinformation.h"

namespace udsNames {

static QString dsc = QVariant::fromValue(Enums::ServiceTypes::DiagnosticSessionControl).toString();
static QString cc = QVariant::fromValue(Enums::ServiceTypes::CommunicationControl).toString();
static QString cdi = QVariant::fromValue(Enums::ServiceTypes::ClearDiagnosticInformation).toString();

}
