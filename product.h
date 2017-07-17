#ifndef PRODUCT_H
#define PRODUCT_H

#include <QObject>

class Product : public QObject
{
    Q_OBJECT
    Q_PROPERTY(int idNum READ idNum WRITE setIdNum NOTIFY idNumChanged)



public:
    explicit Product(QObject *parent = nullptr);
    int idNum() const {return _idNum;}
    void setIdNum(const int newIdNum);

signals:
    void idNumChanged();

public slots:

private:
    int _idNum;
};

#endif // PRODUCT_H
