#ifndef COUNTMODEL_H
#define COUNTMODEL_H

#include <QObject>

class CountModel : public QObject
{
    Q_OBJECT
public:
    explicit CountModel(QObject *parent = 0);

signals:

public slots:
};

#endif // COUNTMODEL_H