#ifndef SPLOGMODEL_H
#define SPLOGMODEL_H


#include <QSqlTableModel>
class SPLogModel : public QSqlTableModel
{
    Q_OBJECT
public:
    explicit SPLogModel(QObject *parent = nullptr);
    QVariant data(const QModelIndex &index, int role) const override;
    QHash<int, QByteArray> roleNames() const override;

signals:

public slots:
};

#endif // SPLOGMODEL_H
