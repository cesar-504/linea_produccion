#include "productionline.h"
#include <QStringRef>
#include <memory>

ProductionLine::ProductionLine(QObject *parent) : QObject(parent)
{

}

void ProductionLine::setSender(ISender *newSender)
{
    if(_sender==newSender) return;
    _sender=newSender;
    connect(_sender,&ISender::msgReceived,this,&ProductionLine::msgHandler);
    connect(_sender,&ISender::error,this,&ProductionLine::errorHandler);

    emit senderChanged();

}

void ProductionLine::setIsStart(const bool newIsStart)
{
    if(_isStart==newIsStart) return;
    _isStart=newIsStart;
    emit isStartChanged();

}

void ProductionLine::start(int station, QJSValue callback)
{
    if(station<0 || station >99) {
        emit error("error el numero de estación debe ser mayor o igual a 0 y menor o igual a 100");
        return;
    }
    QString c = "^01";
    if(station<10) c.append("0");
    c.append(QString::number(station));
    c.append("$\n");
    auto conn = std::make_shared<QMetaObject::Connection>();
    *conn = QObject::connect(this, &ProductionLine::started,
        [this,conn,&callback,station](int s){
            if(station == s && callback.isCallable())
                callback.call();
            disconnect(*conn);
        });
    sendMsg(c);

}

void ProductionLine::stop(int station, QJSValue callback)
{
    if(station<0 || station >99) {
        emit error("error el numero de estación debe ser mayor o igual a 0 y menor o igual a 100");
        return;
    }
    QString c = "^02";
    if(station<10) c.append("0");
    c.append(QString::number(station));
    c.append("$\n");
    auto conn = std::make_shared<QMetaObject::Connection>();
    *conn = QObject::connect(this, &ProductionLine::stoped,
        [this,conn,&callback,station](int s){
            if(station == s && callback.isCallable())
                callback.call();
            disconnect(*conn);
        });
    sendMsg(c);
}
void ProductionLine::sendMsg(const QString msg)
{
    _sender->sendMsg(msg);
}

bool ProductionLine::ck50(QString msg)
{
    if(!msg.startsWith("50")) return false;
    QStringRef sub(&msg,2,2);
    if(sub == "01" ){
        sub = QStringRef(&msg,6,2);
        if(sub == "02") {
            emit error("error al intentar encender estaciones");
            return false;
        }else{
            sub = QStringRef(&msg,4,2);
            emit started(sub.toInt(nullptr,10));
        }

    }else if(sub == "02"){
        sub = QStringRef(&msg,6,2);
        if(sub == "02"){
            emit error("error al intentar apagar estaciones");
            return false;
        }else{
            sub = QStringRef(&msg,4,2);
            emit stoped(sub.toInt(nullptr,10));
        }
    }
    return true;
}

bool ProductionLine::ck51(QString msg)
{
    if(!msg.startsWith("51")) return false;
    int from, to;
    QStringRef sub(&msg,2,2);
    bool * b = nullptr;
    bool * b2 = nullptr;
    from = sub.toInt(b,10);
    sub = QStringRef(&msg,6,2);
    to  = sub.toInt(b2,10);
    if(b && b2){
        emit entryOn(from,to);
        sendMsg("^505100$");
        return true;
    }else{
        emit warning("comando 51 no valido recibido : " + msg);
        sendMsg("^505101$");
        return false;
    }

}

bool ProductionLine::ck52(QString msg)
{
    if(!msg.startsWith("52")) return false;
    int from, to;
    QStringRef sub(&msg,2,2);
    bool * b = nullptr;
    bool * b2 = nullptr;
    from = sub.toInt(b,10);
    sub = QStringRef(&msg,6,2);
    to  = sub.toInt(b2,10);
    if(b && b2){
        emit exitOn(from,to);
        sendMsg("^505200$");
        return false;
    }else{
        emit warning("comando 52 no valido");
        sendMsg("^505201$");
        return true;
    }
}

void ProductionLine::msgHandler(QString msg)
{
    auto m = msg.trimmed();
    if(!m.startsWith("^") || !m.endsWith("$")){
        emit warning("error de formato en comando entrante");
        return;
    }
    m.chop(1);
    m.remove(0,1);
    if(!ck50(m) && !ck51(m) && !ck52(m) ){
        emit warning("error de formato en comando entrante");
    }

}

void ProductionLine::errorHandler(QString errorMsg)
{
    emit error(errorMsg);
}
