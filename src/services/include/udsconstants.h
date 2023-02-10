#include "enums.h"
#include "diagnosticsessioncontrol.h"
#include "communicationcontrol.h"
#include "cleardiagnosticinformation.h"
#include "servicefactory.h"

template<typename T>
QString enumToString(T val)
{
    //QString str = QVariant::fromValue(val).toString();
    QString res = "";//str.at(0);
    //for (int i = 1; i < str.length(); ++i) {
    //    if (str.at(i).isUpper())
    //        res.append(" " + str.mid(i, 1).toLower());
    //}
    return res;
}

namespace udsConstants {
    static const int answerSuppress = 0x80;
}
