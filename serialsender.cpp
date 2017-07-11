#include "serialsender.h"

QStringList SerialSender::availablePorts()
{
    auto ports = QSerialPortInfo::availablePorts();
    QStringList list;
    for( const QSerialPortInfo &p :ports ){
        list.append(p.portName());
    }
    return list;
}

SerialSender::SerialSender(QObject *parent) : ISender(parent)
{
    _serialPort = new QSerialPort(this);
    connect(_serialPort,
            static_cast<void (QSerialPort::*)(QSerialPort::SerialPortError)>(&QSerialPort::error),
            this, &SerialSender::errorHandler
            );
    connect(_serialPort,&QSerialPort::readyRead,this,&SerialSender::readHandler);
    connect(_serialPort, &QSerialPort::baudRateChanged,this,&SerialSender::baudRateChanged);
}

void SerialSender::setPortName(const QString newPortName)
{
    if(_serialPort->portName()==newPortName) return;
    _serialPort->close();
    _serialPort->setPortName(newPortName);
    emit portNameChanged();
}

void SerialSender::setIsOpen(const bool newIsOpen)
{
    if(_serialPort->isOpen()==newIsOpen) return;
    if(_serialPort->isOpen())
        _serialPort->close();
    else
        _serialPort->open(QIODevice::ReadWrite);
    emit isOpenChanged();

}

void SerialSender::setBaudRate(const int newBaudRate)
{
    if(_serialPort->baudRate() == newBaudRate ) return;
    _serialPort->setBaudRate(newBaudRate);
}

void SerialSender::sendMsg(const QString msg)
{
    _serialPort->write(msg.toUtf8());
}

void SerialSender::readHandler()
{
    QString data = _serialPort->readAll();
    emit msgReceived(data);
}


void SerialSender::errorHandler(QSerialPort::SerialPortError e)
{
    if(e != QSerialPort::NoError )
        emit error(_serialPort->errorString());
}
