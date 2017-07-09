#ifndef SERIALSENDER2_H
#define SERIALSENDER2_H

#include <QObject>
#include <QString>
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>
#include <QStringList>
#include "isender.h"
class SerialSender : public ISender
{

    Q_OBJECT
    Q_PROPERTY(QString portName READ portName WRITE setPortName NOTIFY portNameChanged)
    Q_PROPERTY(bool isOpen READ isOpen WRITE setIsOpen NOTIFY isOpenChanged)





public:
    static  QStringList availablePorts();

    explicit SerialSender(QObject *parent = nullptr);
    QString portName() const {return _serialPort->portName();}
    void setPortName(const QString newPortName);
    bool isOpen() const {return _serialPort->isOpen();}
    void setIsOpen(const bool newIsOpen);


    void sendMsg(const QString msg) override;


signals:
    void portNameChanged();
    void isOpenChanged();

public slots:
    void readHandler();
private:
    QSerialPort * _serialPort;
};

#endif // SERIALSENDER2_H
