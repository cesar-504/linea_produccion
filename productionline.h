#ifndef PRODUCTIONLINE_H
#define PRODUCTIONLINE_H

#include <QObject>
#include <QString>
#include <QJSValue>
#include <functional>
#include <QList>
#include <QQmlListProperty>
#include "isender.h"
#include "productionlinedb.h"
#include "splogmodel.h"
#include "station.h"
#include "product.h"
#include "countmodel.h"

class ProductionLine : public QObject
{
    Q_OBJECT
    Q_PROPERTY(ISender * sender READ sender WRITE setSender NOTIFY senderChanged)
    Q_PROPERTY(SPLogModel * spModel READ spModel WRITE setSpModel NOTIFY spModelChanged)
    Q_PROPERTY(bool isStart READ isStart WRITE setIsStart NOTIFY isStartChanged)
    Q_PROPERTY(QQmlListProperty<Station> stations READ stations  NOTIFY stationsChanged)
    Q_PROPERTY(QQmlListProperty<Product> products READ products /*WRITE setProducts*/ NOTIFY productsChanged)
    Q_PROPERTY(CountModel * countModel READ countModel NOTIFY countModelChanged)





    Q_CLASSINFO("DefaultProperty", "stations")




//static
private:




public:
    explicit ProductionLine(QObject *parent = nullptr);

    //get set
    ISender * sender() const {return _sender;}
    void setSender(ISender * newSender);
    bool isStart() const {return _isStart;}
    void setIsStart(const bool newIsStart);
    SPLogModel * spModel() const {return _spModel;}
    void setSpModel(SPLogModel * newSpModel);
    QQmlListProperty<Station> stations() {return QQmlListProperty<Station>(this,_stations);}
    QQmlListProperty<Product> products() {return QQmlListProperty<Product> (this,_products);}
    CountModel * countModel() const {return _countModel;}



    //public functions
    void start(int station=0, QJSValue callback = QJSValue());
    void stop(int station=0, QJSValue callback = QJSValue());

signals:
    void error(QString error);
    void warning(QString error);
    void log(QString msg);
    void senderChanged();
    void isStartChanged();
    void spModelChanged();
    void entryOn(int from, int to);
    void exitOn(int from, int to);
    void move(int from, int to,int idNum);
    void started(int station=0);
    void stopped(int station=0);
    void stationsChanged();
    void productsChanged();

    void countModelChanged();

private:
    void sendMsg(const QString msg);
    Product * productInStation(int idStation);



    bool ck50(QString msg);
    bool ck51(QString msg);
    bool ck52(QString msg);

    void setStationOnOff(bool val);


private slots:
    void msgHandler(QString msg);
    void errorHandler(QString errorMsg);

private:
    ISender * _sender;
    bool _isStart;
    ProductionLineDb * _db;
    CountModel * _countModel;
    SPLogModel * _spModel;
    QList<Station *> _stations;
    QList<Product *> _products;
};

#endif // PRODUCTIONLINE_H
