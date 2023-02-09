#include "include/cleardiagnosticinformation.h"
#include "include/udsservices.h"

clearDiagnosticInformation::clearDiagnosticInformation()
    : clearDiagnosticInfoLabel(new QLabel("Group of DTC to clear:"))
    , clearDiagnosticInfoLineEdit(new QLineEdit("FFFFFF"))
{
    clearDiagnosticInfoLineEdit->setValidator(new QRegExpValidator(QRegExp("[0-9a-fA-F]{0,6}")));
    connect(clearDiagnosticInfoLineEdit, SIGNAL(textChanged(QString)), this, SLOT(onTextChanged(QString)));

    widgets.append(clearDiagnosticInfoLabel);
    widgets.append(clearDiagnosticInfoLineEdit);
}

QList<int> *clearDiagnosticInformation::request()
{
    QList<int>* request = new QList<int>();
    request->append(Enums::ServiceTypes::ClearDiagnosticInformation);
    return request;
}

void clearDiagnosticInformation::onTextChanged(QString)
{
    if (clearDiagnosticInfoLineEdit)
        clearDiagnosticInfoLineEdit->text() = clearDiagnosticInfoLineEdit->text().toUpper();
}
