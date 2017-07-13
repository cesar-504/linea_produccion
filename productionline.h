#ifndef PRODUCTIONLINE_H
#define PRODUCTIONLINE_H

#include <QObject>
#include <QString>
#include <QJSValue>
#include <functional>
#include "isender.h"
#include "productionlinedb.h"


class ProductionLine : public QObject
{
    Q_OBJECT
    Q_PROPERTY(ISender * sender READ sender WRITE setSender NOTIFY senderChanged)
    Q_PROPERTY(bool isStart READ isStart WRITE setIsStart NOTIFY isStartChanged)

//static
private:




public:
    explicit ProductionLine(QObject *parent = nullptr);

    //get set
    ISender * sender() const {return _sender;}
    void setSender(ISender * newSender);
    bool isStart() const {return _isStart;}
    void setIsStart(const bool newIsStart);


    //public functions
    void start(int station=0, QJSValue callback = QJSValue());
    void stop(int station=0, QJSValue callback = QJSValue());

signals:
    void error(QString error);
    void warning(QString error);
    void log(QString msg);
    void senderChanged();
    void isStartChanged();
    void entryOn(int from, int to);
    void exitOn(int from, int to);
    void started(int station=0);
    void stopped(int station=0);
private:
    void sendMsg(const QString msg);


    bool ck50(QString msg);
    bool ck51(QString msg);
    bool ck52(QString msg);


private slots:
    void msgHandler(QString msg);
    void errorHandler(QString errorMsg);

private:
    ISender * _sender;
    bool _isStart;
    ProductionLineDb * _db;

};

#endif // PRODUCTIONLINE_H
