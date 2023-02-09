#ifndef CLEARDIAGNOSTICINFORMATION_H
#define CLEARDIAGNOSTICINFORMATION_H

#include "udsservice.h"

#include <QObject>

class clearDiagnosticInformation : public udsService
{

private:
    clearDiagnosticInformation(const clearDiagnosticInformation&);
    clearDiagnosticInformation& operator=(const clearDiagnosticInformation&);

public:
    clearDiagnosticInformation();
    virtual ~clearDiagnosticInformation() {}
    QList<int> *request() override;

private:
    QLabel *clearDiagnosticInfoLabel;
    QLineEdit *clearDiagnosticInfoLineEdit;

public slots:
    void onTextChanged(QString);
};

#endif // CLEARDIAGNOSTICINFORMATION_H
