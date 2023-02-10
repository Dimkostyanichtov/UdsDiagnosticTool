#include "include/communicationcontrol.h"

communicationControl::communicationControl()
    : communicationIdLabel(new QLabel("Function ID:"))
    , communicationIdComboBox(new QComboBox())
    , communicationTypeLabel(new QLabel("Communication type:"))
    , communicationTypeComboBox(new QComboBox())
    , answerSuppressLabel(new QLabel("Answer:"))
    , answerSuppressComboBox(new QComboBox())
{
    widgets = new QList<QWidget*>;

    communicationIdComboBox->addItem("Enable Rx and Tx");
    communicationIdComboBox->addItem("Enable Rx and disable Tx");
    communicationIdComboBox->addItem("Disable Rx and enable Tx");
    communicationIdComboBox->addItem("Disable Rx and Tx");

    communicationTypeComboBox->addItem("Normal communication messages");
    communicationTypeComboBox->addItem("Normal and Network management communication messages");

    answerSuppressComboBox->addItem("To answer");
    answerSuppressComboBox->addItem("Don't answer");

    widgets->append(communicationIdLabel);
    widgets->append(communicationIdComboBox);
    widgets->append(communicationTypeLabel);
    widgets->append(communicationTypeComboBox);
    widgets->append(answerSuppressLabel);
    widgets->append(answerSuppressComboBox);
}

QList<int>* communicationControl::request()
{
    QList<int>* request = new QList<int>();
    request->append(Enums::ServiceTypes::CommunicationControl);
    request->append(communicationIdComboBox->currentIndex());
    switch (communicationTypeComboBox->currentIndex()) {
    case 0:
        request->append(0x1);
        break;
    case 1:
        request->append(0x3);
        break;
    }
    if (answerSuppressComboBox->currentIndex() == 1)
        request[1] += udsConstants::answerSuppress;
    return request;
}
