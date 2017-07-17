#ifndef STATION_H
#define STATION_H

#include <QObject>
#include <QString>
#include <QList>
#include <QQmlListProperty>
#include "product.h"
class Station : public QObject
{
    Q_OBJECT
    Q_PROPERTY(int  idNum READ idNum WRITE setIdNum NOTIFY idNumChanged)
    Q_PROPERTY(QString name READ name WRITE setName NOTIFY nameChanged)
    Q_PROPERTY(Types type READ type WRITE setType NOTIFY typeChanged)
    Q_PROPERTY(QQmlListProperty<Product> productList READ productList /*WRITE setProductList */ NOTIFY productListChanged)
    Q_PROPERTY(int count READ count  NOTIFY productListChanged)
    Q_PROPERTY(int msToDel READ msToDel WRITE setMsToDel NOTIFY msToDelChanged)
    Q_PROPERTY(bool isOn READ isOn  NOTIFY isOnChanged)





public:
    enum  Types {
        Entry=0,
        Exit,
        ExitError,
        Verification,
        Repair
    };
    Q_ENUM(Types)
    explicit Station(QObject *parent = nullptr);
    int  idNum() const {return _idNum;}
    void setIdNum(const int  newIdNum);
    QString name() const {return _name;}
    void setName(const QString newName);
    Types type() const {return _type;}
    void setType(const Types newType);
    QQmlListProperty<Product> productList() {return QQmlListProperty<Product>(this,_productList);}
    Q_INVOKABLE int productCount(){return _productList.size();}
    //    void setProductList(const QList<Product *> newProductList);
    int count() const {return _productList.size();}
    int msToDel() const {return _msToDel;}
    void setMsToDel(const int newMsToDel);
    bool isOn() const {return _isOn;}
    void setIsOn(const bool newIsOn);

    void addProduct(Product * p);
    int moveToStation(Station * s);
    void deleteProduct();
    void deleteProduct(int IdProduct);


signals:
    void idNumChanged();
    void nameChanged();
    void typeChanged();
    void productListChanged();
    void msToDelChanged();
    void isOnChanged();

private:
    int  _idNum;
    QString _name;
    Types _type;
    QList<Product *>  _productList;
    int _msToDel=1500;
    bool _isOn;
};

#endif // STATION_H
