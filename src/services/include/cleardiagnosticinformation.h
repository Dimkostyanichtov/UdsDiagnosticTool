#ifndef CLEARDIAGNOSTICINFORMATION_H
#define CLEARDIAGNOSTICINFORMATION_H

#include "udsservice.h"

#include <QObject>

class clearDiagnosticInformation : public udsService
{
    Q_OBJECT

private:
    clearDiagnosticInformation(const clearDiagnosticInformation&);
    clearDiagnosticInformation& operator=(const clearDiagnosticInformation&);
    clearDiagnosticInformation& operator=(clearDiagnosticInformation&&);

public:
    clearDiagnosticInformation(QObject *parent = nullptr);
    virtual ~clearDiagnosticInformation() {}
    QList<int> *request() override;
    QList<QWidget*>* getWidgets() override;

private:
    QLabel *clearDiagnosticInfoLabel;
    QLineEdit *clearDiagnosticInfoLineEdit;

public slots:
    void onTextChanged(const QString &);
};

#endif // CLEARDIAGNOSTICINFORMATION_H
