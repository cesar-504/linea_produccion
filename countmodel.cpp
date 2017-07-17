#include "countmodel.h"
#include <QDebug>
#include <QSqlError>
#include <QSqlQuery>
#include <QSqlRecord>

CountModel::CountModel(QObject *parent) : QSqlQueryModel(parent)
{
    update();
}

QVariant CountModel::data(const QModelIndex &index, int role) const
{
    if (role < Qt::UserRole){
        return QSqlQueryModel::data(index, role);
    }

    const QSqlRecord sqlRecord = record(index.row());
    return sqlRecord.value(role - Qt::UserRole);
}

QHash<int, QByteArray> CountModel::roleNames() const
{
    QHash<int, QByteArray> names;
    names[Qt::UserRole] = "totalPr";
    names[Qt::UserRole + 1] = "totalOkPr";
    names[Qt::UserRole + 2] = "totalErrorPr";
    return names;
}

void CountModel::update()
{
    QSqlQuery query;
    query.exec("select"
               "((select count(*) from StationProductLog where toStation = 5 ) +"
               "(select count(*) from StationProductLog where toStation = 9)) as totalPr,"
               "(select count(*) from StationProductLog where toStation = 5 ) as totalOkPr, "
               "(select count(*) from StationProductLog where toStation = 9 ) as totalErroPr"
    );
    setQuery(query);

}
