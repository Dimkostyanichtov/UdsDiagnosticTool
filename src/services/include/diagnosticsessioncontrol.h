#ifndef DIAGNOSTICSESSIONCONTROL_H
#define DIAGNOSTICSESSIONCONTROL_H

#include "udsservice.h"

class diagnosticSessionControl : public udsService
{
private:
    diagnosticSessionControl(const diagnosticSessionControl&);
    diagnosticSessionControl& operator=(const diagnosticSessionControl&);

public:
    diagnosticSessionControl();
    virtual ~diagnosticSessionControl() {}
    QList<int> *request() override;

private:
    QLabel *sessionTypeLabel;
    QComboBox *sessionTypeComboBox;
    QLabel *answerSuppressLabel;
    QComboBox *answerSuppressComboBox;
};

#endif // DIAGNOSTICSESSIONCONTROL_H
