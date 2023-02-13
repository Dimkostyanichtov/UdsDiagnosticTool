#include "include/diagnosticsessioncontrol.h"

diagnosticSessionControl::diagnosticSessionControl() {}

QList<int>* diagnosticSessionControl::request()
{
    QList<int>* request = new QList<int>();
    request->append(Enums::ServiceTypes::DiagnosticSessionControl);
    request->append(sessionTypeComboBox->currentIndex()+1);
    if (answerSuppressComboBox->currentIndex() == 1)
        request[1] += udsConstants::answerSuppress;
    return request;
}

QList<QWidget *> *diagnosticSessionControl::getWidgets()
{
    sessionTypeLabel = new QLabel("Session type:");
    sessionTypeComboBox = new QComboBox();
    answerSuppressLabel = new QLabel("Answer:");
    answerSuppressComboBox = new QComboBox();

    widgets = new QList<QWidget*>;

    sessionTypeLabel->setContentsMargins(0, 6, 0, 3);

    sessionTypeComboBox->addItem("Diagnostic session");
    sessionTypeComboBox->addItem("Programming session");
    sessionTypeComboBox->addItem("Extended session");
    sessionTypeComboBox->setMaximumWidth(130);

    answerSuppressLabel->setContentsMargins(0, 6, 0, 3);

    answerSuppressComboBox->addItem("To answer");
    answerSuppressComboBox->addItem("Don't answer");
    answerSuppressComboBox->setMaximumWidth(90);

    widgets->append(sessionTypeLabel);
    widgets->append(sessionTypeComboBox);
    widgets->append(answerSuppressLabel);
    widgets->append(answerSuppressComboBox);
    return widgets;
}
