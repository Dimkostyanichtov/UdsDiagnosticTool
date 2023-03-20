#ifndef UDSSERVICE_H
#define UDSSERVICE_H

#include <QByteArrayList>
#include <QWidget>
#include <QLabel>
#include <QComboBox>
#include <QLineEdit>
#include <QString>
#include <QMap>
#include <QObject>
#include <QRegExp>

#include "udsconstants.h"
#include "enums.h"


/*!
 * \class udsService
 * \brief The abstract class for services implementation
 *
 *  Each service consists of number of widgets which dinamically creates and adds to form when corresponding field selected.
 *  Each service has request function which returns UDS request bytes string.
 */
class udsService : public QObject
{
    Q_OBJECT
protected:
    QList<QWidget*>* widgets {};

public:
    udsService() {}
    virtual ~udsService() { delete[] widgets; }
    virtual QList<int> *request() = 0;
    virtual QList<QWidget*>* getWidgets() = 0;

    static QString listToString(const QList<int> list)
    {
        QStringList result;
        for (int val : list)
            result.append(QString::number(val, 16).rightJustified(2, '0'));
        return result.join('-');
    }
};

#endif // UDSSERVICE_H
