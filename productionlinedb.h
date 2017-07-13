#ifndef PRODUCTIONLINEDB_H
#define PRODUCTIONLINEDB_H

#include <QObject>
#include <QString>
class ProductionLineDb : public QObject
{
    Q_OBJECT
public:
    static bool initDB();
    static void createTables();
    explicit ProductionLineDb(QObject *parent = nullptr);

    void startPL();
    void stopPL();
    void start(const int station);
    void stop(const int station);
    void entry(const int from , const int to);
    void exit(const int from , const int to);

private:
    void entryExit(const int from , const int to,bool isEntry);
    void onOff(const bool totalOnOff,const bool isOn,const int station=0);
signals:
    void error(QString errorMsg);

public slots:
};

#endif // PRODUCTIONLINEDB_H
