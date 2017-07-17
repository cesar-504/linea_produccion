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

private:
    void entryExit(const int from , const int to,bool isEntry);
signals:
    void error(QString errorMsg);
public slots:
    Q_INVOKABLE void entry(const int from , const int to);
    void exit(const int from , const int to);
};

#endif // SPLOGMODEL_H
