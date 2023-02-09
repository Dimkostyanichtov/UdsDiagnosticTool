#include "include/diagnosticsessioncontrol.h"
#include "include/udsservices.h"

diagnosticSessionControl::diagnosticSessionControl()
    : sessionTypeLabel(new QLabel("Session type:"))
    , sessionTypeComboBox(new QComboBox())
    , answerSuppressLabel(new QLabel("Answer:"))
    , answerSuppressComboBox(new QComboBox())
{
    sessionTypeComboBox->addItem("Diagnostic session");
    sessionTypeComboBox->addItem("Programming session");
    sessionTypeComboBox->addItem("Extended session");

    answerSuppressComboBox->addItem("To answer");
    answerSuppressComboBox->addItem("Don't answer");

    widgets.append(sessionTypeLabel);
    widgets.append(sessionTypeComboBox);
    widgets.append(answerSuppressLabel);
    widgets.append(answerSuppressComboBox);
}

QList<int>* diagnosticSessionControl::request()
{
    QList<int>* request = new QList<int>();
    request->append(Enums::ServiceTypes::DiagnosticSessionControl);
    request->append(sessionTypeComboBox->currentIndex()+1);
    if (answerSuppressComboBox->currentIndex() == 1)
        request[1] += udsConstants::answerSuppress;
    return request;
}
