#include "include/diagnosticsessioncontrol.h"

diagnosticSessionControl::diagnosticSessionControl()
{

}

diagnosticSessionControl::~diagnosticSessionControl() {}

QByteArrayList* diagnosticSessionControl::request()
{
    return new QByteArrayList();
}
