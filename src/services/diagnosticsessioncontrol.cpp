#include "include/diagnosticsessioncontrol.h"

diagnosticSessionControl::diagnosticSessionControl()
{
    dscLabel = new QLabel("Diagnostic session control");
}

diagnosticSessionControl::~diagnosticSessionControl() {}

QByteArrayList* diagnosticSessionControl::request()
{
    return new QByteArrayList();
}
