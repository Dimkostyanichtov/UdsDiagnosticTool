#include "include/diagnosticsessioncontrol.h"

diagnosticSessionControl::diagnosticSessionControl() {}

diagnosticSessionControl::~diagnosticSessionControl() {}

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
    sessionTypeLabel->setFont(QFont("Calibri", 11));

    sessionTypeComboBox->addItem("Diagnostic session");
    sessionTypeComboBox->addItem("Programming session");
    sessionTypeComboBox->addItem("Extended session");
    sessionTypeComboBox->setMaximumWidth(160);
    sessionTypeComboBox->setFont(QFont("Calibri", 11));

    answerSuppressLabel->setContentsMargins(0, 6, 0, 3);
    answerSuppressLabel->setFont(QFont("Calibri", 11));

    answerSuppressComboBox->addItem("To answer");
    answerSuppressComboBox->addItem("Don't answer");
    answerSuppressComboBox->setMaximumWidth(110);
    answerSuppressComboBox->setFont(QFont("Calibri", 11));

    widgets->append(sessionTypeLabel);
    widgets->append(sessionTypeComboBox);
    widgets->append(answerSuppressLabel);
    widgets->append(answerSuppressComboBox);

    return widgets;
}
