#ifndef DIAGNOSTICSESSIONCONTROL_H
#define DIAGNOSTICSESSIONCONTROL_H

#include <QLabel>
#include <QComboBox>

#include "udsservice.h"

class diagnosticSessionControl : public udsService
{
public:
    diagnosticSessionControl();
    virtual ~diagnosticSessionControl();
    QByteArrayList *request() override;

private:
    QLabel *sessionTypeLabel;
    QComboBox *sessionTypeComboBox;
    QLabel *answerSuppressLabel;
    QComboBox *answerSuppressComboBox;
};

#endif // DIAGNOSTICSESSIONCONTROL_H
