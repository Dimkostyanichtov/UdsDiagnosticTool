#include "include/cleardiagnosticinformation.h"
#include "../../mainwindow.h"

clearDiagnosticInformation::clearDiagnosticInformation(QObject *parent)
    : clearDiagnosticInfoLabel(new QLabel("Group of DTC to clear:"))
    , clearDiagnosticInfoLineEdit(new QLineEdit("FFFFFF"))
{
    widgets = new QList<QWidget*>;

    clearDiagnosticInfoLineEdit->setValidator(new QRegExpValidator(QRegExp("[0-9a-fA-F]{0,6}")));
    QObject::connect(clearDiagnosticInfoLineEdit, &QLineEdit::textChanged, this, &clearDiagnosticInformation::onTextChanged);

    widgets->append(clearDiagnosticInfoLabel);
    widgets->append(clearDiagnosticInfoLineEdit);
}

QList<int> *clearDiagnosticInformation::request()
{
    QList<int>* request = new QList<int>();
    request->append(Enums::ServiceTypes::ClearDiagnosticInformation);
    return request;
}

void clearDiagnosticInformation::onTextChanged(const QString &)
{
    clearDiagnosticInfoLineEdit->setText(clearDiagnosticInfoLineEdit->text().toUpper());
}
