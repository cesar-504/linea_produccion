#ifndef PRODUCT_H
#define PRODUCT_H

#include <QObject>
#include "station.h"
class Product : public QObject
{
    Q_OBJECT
    Q_PROPERTY(int idNum READ idNum WRITE setIdNum NOTIFY idNumChanged)
    Q_PROPERTY( Station * station READ station /*WRITE setStation*/ NOTIFY stationChanged)





public:
    explicit Product(QObject *parent = nullptr);
    int idNum() const {return _idNum;}
    void setIdNum(const int newIdNum);
    Station * station() const {return _station;}
    void setStation(Station *newStation);

signals:
    void idNumChanged();
    void stationChanged();

public slots:

private:
    int _idNum;
    Station * _station;
};

#endif // PRODUCT_H
