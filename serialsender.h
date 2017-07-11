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
    Q_PROPERTY(int baudRate READ baudRate WRITE setBaudRate NOTIFY baudRateChanged)







public:
    static  QStringList availablePorts();

    explicit SerialSender(QObject *parent = nullptr);
    QString portName() const {return _serialPort->portName();}
    void setPortName(const QString newPortName);
    bool isOpen() const {return _serialPort->isOpen();}
    void setIsOpen(const bool newIsOpen);
    int baudRate() const {return _serialPort->baudRate();}
    void setBaudRate(const int newBaudRate);


    void sendMsg(const QString msg) override;


signals:
    void portNameChanged();
    void isOpenChanged();
    void baudRateChanged();

public slots:
    void readHandler();
    void errorHandler(QSerialPort::SerialPortError e);
private:
    QSerialPort * _serialPort;
};

#endif // SERIALSENDER2_H
