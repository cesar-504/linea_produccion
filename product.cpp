#include "product.h"

Product::Product(QObject *parent) : QObject(parent)
{

}

void Product::setIdNum(const int newIdNum)
{
    if(_idNum==newIdNum) return;
    _idNum=newIdNum;
    emit idNumChanged();

}

void Product::setStation(Station *newStation)
{
    if(_station==newStation) return;
    _station=newStation;
    emit stationChanged();

}
