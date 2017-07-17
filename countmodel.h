#ifndef COUNTMODEL_H
#define COUNTMODEL_H

#include <QObject>
#include <QSqlQueryModel>
class CountModel :public QSqlQueryModel
{
    Q_OBJECT
public:
    explicit CountModel(QObject *parent = 0);
    QVariant data(const QModelIndex &index, int role) const override;
    QHash<int, QByteArray> roleNames() const override;
signals:

public slots:
    void update();
};

#endif // COUNTMODEL_H
