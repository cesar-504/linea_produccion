#include "splogmodel.h"
#include <QDateTime>
#include <QDebug>
#include <QSqlError>
#include <QSqlRecord>
#include <QSqlQuery>
static const char *conversationsTableName = "StationProductLog";
SPLogModel::SPLogModel(QObject *parent) : QSqlTableModel(parent)
{
    setTable(conversationsTableName);
    setSort(0, Qt::DescendingOrder);
    setEditStrategy(QSqlTableModel::OnManualSubmit);
    select();
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
    QHash<int, QByteArray> names;
    names[Qt::UserRole] = "id";
    names[Qt::UserRole + 1] = "from";
    names[Qt::UserRole + 2] = "to";
    names[Qt::UserRole + 3] = "product";
    names[Qt::UserRole + 4] = "timeLog";
    names[Qt::UserRole + 5] = "action";
    return names;
}

void SPLogModel::entry(const int from, const int to)
{
    entryExit(from,to,true);
}

void SPLogModel::exit(const int from, const int to)
{
    entryExit(from,to,false);
}

void SPLogModel::entryExit(const int from, const int to, bool isEntry)
{
    const QString timestamp = QDateTime::currentDateTime().toString(Qt::ISODate);
    QSqlRecord rec = record();
    rec.setValue("fromStation",from);
    rec.setValue("toStation",to);
    rec.setValue("id_Product",1);
    rec.setValue("timeLog",timestamp);
    rec.setValue("id_LogAction",(isEntry)? 1: 2);
    qDebug() << rec.value(3);
    if (!insertRecord(rowCount(), rec)) {
        qWarning() << lastError().text();
        emit error(lastError().text());
        return;
    }
    submitAll();
    emit updated();
}

