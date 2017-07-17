#include "productionline.h"
#include <QStringRef>
#include <QDebug>
#include <memory>
#include <QTimer>
ProductionLine::ProductionLine(QObject *parent) : QObject(parent)
{
    _db = new ProductionLineDb(this);

    connect(this,&ProductionLine::started,_db,&ProductionLineDb::start);
    connect(this,&ProductionLine::stopped,_db,&ProductionLineDb::stop);
    _countModel = new CountModel(this);


}

void ProductionLine::setSender(ISender *newSender)
{
    if(_sender==newSender) return;
    _sender=newSender;
    _sender->setParent(this);
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

void ProductionLine::setSpModel(SPLogModel *newSpModel)
{
    if(_spModel==newSpModel) return;
    _spModel=newSpModel;
    _spModel->setParent(this);
    qDebug() << "0000000000000000000";
    connect(this,&ProductionLine::entryOn,_spModel,&SPLogModel::entry);
    connect(this,&ProductionLine::exitOn,_spModel,&SPLogModel::exit);
    emit spModelChanged();

    connect(_spModel,&SPLogModel::updated,_countModel, &CountModel::update);

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
    *conn = QObject::connect(this, &ProductionLine::stopped,
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

Product *ProductionLine::productInStation(int idStation)
{
    for(Product * p : _products){
        if(p->station() == _stations.at(idStation)){
            return p;
        }
    }
    return nullptr;
}

bool ProductionLine::ck50(QString msg)
{
    if(!msg.startsWith("50")) return false;
    QStringRef sub(&msg,2,2);
    if(sub == "01" ){
        sub = QStringRef(&msg,6,2);
        if(sub != "00") {
            emit error("error al intentar encender estaciones");
            return false;
        }else{
            sub = QStringRef(&msg,4,2);

            setStationOnOff(true);
            emit started(sub.toInt(nullptr,10));
        }

    }else if(sub == "02"){
        sub = QStringRef(&msg,6,2);
        if(sub != "00"){
            emit error("error al intentar apagar estaciones");
            return false;
        }else{
            sub = QStringRef(&msg,4,2);
            setStationOnOff(false);
            emit stopped(sub.toInt(nullptr,10));
        }
    }
    return true;
}

bool ProductionLine::ck51(QString msg)
{
    if(!msg.startsWith("51")) return false;
    int from, to;
    QStringRef sub(&msg,2,2);
    bool b =false;
    bool b2 =false;
    from = sub.toInt(&b,10);
    sub = QStringRef(&msg,4,2);
    to  = sub.toInt(&b2,10);
    if(b && b2){
        Product * p;
        if(from==0){
            p = new Product(this);
            //Falta sacar id de bd
            static int staticIdNum=1;
            p->setIdNum(staticIdNum);
            staticIdNum++;
            //
            p->setStation(_stations.at(to-1));
            _products.append(p);

        } else {
            p = productInStation(from-1);
            p->setStation(_stations.at(to -1));
        }
        if(_stations.at(to-1)->type() == Station::Exit ||
                _stations.at(to-1)->type() == Station::ExitError){

            QTimer::singleShot(_stations.at(to-1)->msToDel(),
                [this,to,p](){
                    for(int i=0;i<_products.size();++i){
                        if(_products.at(i) == p){
                            _products.removeAt(i);
                            emit  this->productsChanged();
                        }
                    }
                }
            );

        }
        emit productsChanged();
        emit entryOn(from,to);
        emit move(from,to,p->idNum());
        sendMsg("^50"+msg+"00$");
        return true;
    }else{
        emit warning("comando 51 no valido recibido : " + msg);
        sendMsg("^50"+msg+"01$");
        return false;
    }

}

bool ProductionLine::ck52(QString msg)
{

    if(!msg.startsWith("52")) return false;
    int from, to;
    QStringRef sub(&msg,2,2);
    bool b =false;
    bool b2 =false;
    from = sub.toInt(&b,10);
    sub = QStringRef(&msg,4,2);
    to  = sub.toInt(&b2,10);
    if(b && b2){
        emit exitOn(from,to);
        sendMsg("^50"+msg+"00$");
        return true;
    }else{
        emit warning("comando 52 no valido");
        sendMsg("^50"+msg+"01$");
        return false;
    }
}

void ProductionLine::setStationOnOff(bool val)
{
    for(Station *s : _stations)
        s->setIsOn(val);
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
