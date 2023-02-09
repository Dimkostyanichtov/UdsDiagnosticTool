#ifndef COMMUNICATIONCONTROL_H
#define COMMUNICATIONCONTROL_H

#include "udsservice.h"

class communicationControl : public udsService
{
public:
private:
    communicationControl(const communicationControl&);
    communicationControl& operator=(const communicationControl&);

public:
    communicationControl();
    virtual ~communicationControl() {}
    QList<int> *request() override;

private:
    QLabel *communicationIdLabel;
    QComboBox *communicationIdComboBox;
    QLabel *communicationTypeLabel;
    QComboBox *communicationTypeComboBox;
    QLabel *answerSuppressLabel;
    QComboBox *answerSuppressComboBox;
};

#endif // COMMUNICATIONCONTROL_H
