#include "include/cleardiagnosticinformation.h"

clearDiagnosticInformation::clearDiagnosticInformation(QObject *parent) {}

QList<int> *clearDiagnosticInformation::request()
{
    QList<int>* request = new QList<int>();
    request->append(Enums::ServiceTypes::ClearDiagnosticInformation);
    return request;
}

QList<QWidget *> *clearDiagnosticInformation::getWidgets()
{
    clearDiagnosticInfoLabel = new QLabel("Group of DTC to clear:");
    clearDiagnosticInfoLineEdit = new QLineEdit("FFFFFF");

    widgets = new QList<QWidget*>;

    clearDiagnosticInfoLabel->setContentsMargins(0, 6, 0, 3);
    clearDiagnosticInfoLabel->setFont(QFont("Calibri", 11));

    clearDiagnosticInfoLineEdit->setValidator(new QRegExpValidator(QRegExp("[0-9a-fA-F]{0,6}")));
    clearDiagnosticInfoLineEdit->setMaximumWidth(65);
    clearDiagnosticInfoLineEdit->setFont(QFont("Calibri", 11));
    QObject::connect(clearDiagnosticInfoLineEdit, &QLineEdit::textChanged, this, &clearDiagnosticInformation::onTextChanged);

    widgets->append(clearDiagnosticInfoLabel);
    widgets->append(clearDiagnosticInfoLineEdit);

    return widgets;
}

void clearDiagnosticInformation::onTextChanged(const QString &)
{
    if (clearDiagnosticInfoLineEdit)
        clearDiagnosticInfoLineEdit->setText(clearDiagnosticInfoLineEdit->text().toUpper());
}
