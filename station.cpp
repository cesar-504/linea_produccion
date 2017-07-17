#include "station.h"
#include <QDebug>
#include <QTimer>
Station::Station(QObject *parent) : QObject(parent)
{

}

void Station::setIdNum(const int newIdNum)
{
    if(_idNum==newIdNum) return;
    _idNum=newIdNum;
    emit idNumChanged();

}

void Station::setName(const QString newName)
{
    if(_name==newName) return;
    _name=newName;
    emit nameChanged();

}

void Station::setType(const Types newType)
{
    if(_type==newType) return;
    _type=newType;
    emit typeChanged();

}

void Station::setMsToDel(const int newMsToDel)
{
    if(_msToDel==newMsToDel) return;
    _msToDel=newMsToDel;
    emit msToDelChanged();

}

void Station::setIsOn(const bool newIsOn)
{
    if(_isOn==newIsOn) return;
    _isOn=newIsOn;
    emit isOnChanged();

}

//void Station::setProductList(const QList<Product *> newProductList)
//{
//    if(_productList==newProductList) return;
//    _productList=newProductList;
//    emit productListChanged();

//}

void Station::addProduct(Product *p)
{
    _productList.append(p);
    emit productListChanged();
}

int Station::moveToStation(Station *s)
{
    if(_productList.isEmpty()){
        qDebug()<<"intentando mover desde estación vacia";
        return -1;
    }
    auto p = _productList.takeFirst();
    s->addProduct( p );
    emit productListChanged();
    return p->idNum();

}

void Station::deleteProduct()
{
    if(_productList.isEmpty()){
        qDebug()<<"intentando borrar desde estación vacia";
        return;
    }
    _productList.removeFirst();
    emit productListChanged();


}

void Station::deleteProduct(int idProduct)
{
    for(int i =0;i<_productList.size();++i){
        if(_productList.at(i)->idNum() == idProduct){
            _productList.removeAt(i);
            emit productListChanged();
        }
    }
}
