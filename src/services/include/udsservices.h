#include "enums.h"
#include "diagnosticsessioncontrol.h"
#include "communicationcontrol.h"
#include "cleardiagnosticinformation.h"
#include "servicefactory.h"

template<typename T>
QString enumToString(T val)
{
    return QVariant::fromValue(val).toString();
}

namespace udsConstants {
    static const int answerSuppress = 0x80;
}
