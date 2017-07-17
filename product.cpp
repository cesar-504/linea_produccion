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
