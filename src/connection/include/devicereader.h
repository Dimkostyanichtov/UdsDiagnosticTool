#ifndef DEVICEREADER_H
#define DEVICEREADER_H

#include <QObject>

class deviceReader: public QObject
{
    Q_OBJECT

public:
    deviceReader();
    virtual ~deviceReader();
    static QStringList getAvailableDevice() {return QStringList();};
    virtual int setDevice(QString) {return -1;};
    virtual int setDevice(QString, ushort) {return -1;};
    virtual int setDevice(QString, QString) {return -1;};

private:

};

#endif // DEVICEREADER_H
