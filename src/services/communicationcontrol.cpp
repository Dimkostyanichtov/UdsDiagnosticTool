#include "include/communicationcontrol.h"

communicationControl::communicationControl() {}

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

QList<QWidget *> *communicationControl::getWidgets()
{
    communicationIdLabel = new QLabel("Function ID:");
    communicationIdComboBox = new QComboBox();
    communicationTypeLabel = new QLabel("Communication type:");
    communicationTypeComboBox = new QComboBox();
    answerSuppressLabel = new QLabel("Answer:");
    answerSuppressComboBox = new QComboBox();

    widgets = new QList<QWidget*>;

    communicationIdLabel->setContentsMargins(0, 6, 0, 3);
    communicationIdLabel->setFont(QFont("Calibri", 11));

    communicationIdComboBox->addItem("Enable Rx and Tx");
    communicationIdComboBox->addItem("Enable Rx and disable Tx");
    communicationIdComboBox->addItem("Disable Rx and enable Tx");
    communicationIdComboBox->addItem("Disable Rx and Tx");
    communicationIdComboBox->setMaximumWidth(160);
    communicationIdComboBox->setFont(QFont("Calibri", 11));

    communicationTypeLabel->setContentsMargins(0, 6, 0, 3);
    communicationTypeLabel->setFont(QFont("Calibri", 11));

    communicationTypeComboBox->addItem("Normal communication messages");
    communicationTypeComboBox->addItem("Normal and Network management messages");
    communicationTypeComboBox->setMaximumWidth(310);
    communicationTypeComboBox->setFont(QFont("Calibri", 11));

    answerSuppressLabel->setContentsMargins(0, 6, 0, 3);
    answerSuppressLabel->setFont(QFont("Calibri", 11));

    answerSuppressComboBox->addItem("To answer");
    answerSuppressComboBox->addItem("Don't answer");
    answerSuppressComboBox->setMaximumWidth(110);
    answerSuppressComboBox->setFont(QFont("Calibri", 11));

    widgets->append(communicationIdLabel);
    widgets->append(communicationIdComboBox);
    widgets->append(communicationTypeLabel);
    widgets->append(communicationTypeComboBox);
    widgets->append(answerSuppressLabel);
    widgets->append(answerSuppressComboBox);

    return widgets;
}
