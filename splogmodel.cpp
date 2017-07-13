#include "splogmodel.h"
#include <QDateTime>
#include <QDebug>
#include <QSqlError>
#include <QSqlRecord>
#include <QSqlQuery>


SPLogModel::SPLogModel(QObject *parent) : QSqlTableModel(parent)
{
    setTable("StationProductLog");
    //setSort(1, Qt::DescendingOrder);
    setEditStrategy(QSqlTableModel::OnManualSubmit);
}

QVariant SPLogModel::data(const QModelIndex &index, int role) const
{
    if (role < Qt::UserRole)
        return QSqlTableModel::data(index, role);
    const QSqlRecord sqlRecord = record(index.row());
    return sqlRecord.value(role - Qt::UserRole);

}

QHash<int, QByteArray> SPLogModel::roleNames() const
{
    static QHash<int, QByteArray> names;
    names[Qt::UserRole] = "id";
    names[Qt::UserRole + 1] = "fromStation";
    names[Qt::UserRole + 2] = "toStation";
    names[Qt::UserRole + 3] = "product";
    names[Qt::UserRole + 4] = "timeLog";
    names[Qt::UserRole + 5] = "action";
    return names;
}
