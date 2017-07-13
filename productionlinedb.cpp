#include "productionlinedb.h"
#include <QtDebug>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlError>
bool ProductionLineDb::initDB(){
    static bool init =false;
    if(init) return true;
    qDebug() << "inicializando base de datos";
    //SQL
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setHostName("localhost");
    db.setDatabaseName("ProductionLineDB.sqlite");
    bool ok = db.open();
    if(!ok)
        qWarning() << "error al abrir base de datos. ";
    init=ok;
    return ok;
}
void ProductionLineDb::createTables(){
    static bool init =false;
    if(init) return;
    QSqlQuery query;

    if(!query.exec("CREATE TABLE Station ("
                   "id INTEGER NOT NULL ,"
                   "PRIMARY KEY (id)"
                    ")"
                   )){
        qDebug() << "DB: error al crear Station"<< query.lastError();
    }
    if(!query.exec("insert into Station(id) values(1)")){
       qDebug() << "DB: error al insertar en Station" << query.lastError();
    }
    query.exec("insert into Station(id) values(2)");
    query.exec("insert into Station(id) values(3)");
    query.exec("insert into Station(id) values(4)");
    query.exec("insert into Station(id) values(5)");
   if(!query.exec("CREATE TABLE Product ("
                  "id INTEGER NOT NULL ,"
                  "PRIMARY KEY (id)"
                   ")"
                  )){
      qDebug() << "DB: error al crear Product"<< query.lastError();
   }
   //Fix: aun no hay forma de seguir los productos individuales asi que todos se toman como producto 1
    query.exec("insert into Product(id) values(1)");

  if(!query.exec("CREATE TABLE LogAction ("
                 "id INTEGER NOT NULL ,"
                 "name VARCHAR(20) NOT NULL,"
                 "PRIMARY KEY (id)"
               ")"
             )){
     qDebug() << "DB: error al crear LogAction"<< query.lastError();
  }


    query.exec("insert into LogAction(id,name) values(1,'entrada')");
    query.exec("insert into LogAction(id,name) values(2,'salida')");


    if(!query.exec("CREATE TABLE StationProductLog ("
                   "id INTEGER NOT NULL ,"
                   "fromStation INTEGER NOT NULL,"
                   "toStation INTEGER NOT NULL,"
                   "id_Product INTEGER NOT NULL,"
                   "timeLog TIMESTAMP NOT NULL DEFAULT CURRENT_TIMESTAMP,"
                   "id_LogAction INTEGER NOT NULL,"
                   "PRIMARY KEY (id)"
                 ")"
               )){
        qDebug() << "DB: error al crear StationProductLog"<< query.lastError();
    }
    if(!query.exec("CREATE TABLE OnOffLog ("
                   "id INTEGER NOT NULL ,"
                   "totalOnOff INTEGER NOT NULL,"
                   "onOff INTEGER NOT NULL,"
                   "id_Station INTEGER,"
                   "timeLog TIMESTAMP NOT NULL DEFAULT CURRENT_TIMESTAMP,"
                   "PRIMARY KEY (id)"
                 ")"
               )){
        qDebug() << "DB: error al crear OnOffLog"<< query.lastError();
    }


    query.exec("ALTER TABLE StationProductLog ADD FOREIGN KEY (fromStation) REFERENCES Station (id)");
    query.exec("ALTER TABLE StationProductLog ADD FOREIGN KEY (toStation) REFERENCES Station (id)");
    query.exec("ALTER TABLE StationProductLog ADD FOREIGN KEY (id_Product) REFERENCES Product (id)");
    query.exec("ALTER TABLE StationProductLog ADD FOREIGN KEY (id_LogAction) REFERENCES LogAction (id)");
    query.exec("ALTER TABLE OnOffLog ADD FOREIGN KEY (id_Station) REFERENCES Station (id)");


    qDebug() << "DB: tablas creadas";
    init = true;


}

ProductionLineDb::ProductionLineDb(QObject *parent) : QObject(parent)
{
    initDB();
    createTables();
}

void ProductionLineDb::startPL()
{
     onOff(true,true);
}

void ProductionLineDb::stopPL()
{
    onOff(true,false);

}

void ProductionLineDb::start(const int station)
{
    if(station==0) onOff(true,true);
    else onOff(false,true,station);
}

void ProductionLineDb::stop(const int station)
{
    if(station==0) onOff(true,false);
    else onOff(false,false,station);
}

void ProductionLineDb::entry(const int from, const int to)
{
    entryExit(from,to,true);
}

void ProductionLineDb::exit(const int from, const int to)
{
    entryExit(from,to,false);
}

void ProductionLineDb::entryExit(const int from, const int to, bool isEntry)
{
    QSqlQuery query;
    query.prepare("insert into StationProductLog(fromStation,toStation,id_Product,id_LogAction) "
                  "values (?,?,?,?)");
    query.addBindValue(from);
    query.addBindValue(to);
    query.addBindValue(1);
    query.addBindValue((isEntry)? 1: 2);
    if(!query.exec()){
        qDebug() << query.lastError();
        emit error(query.lastError().text());
    }
}

void ProductionLineDb::onOff(const bool totalOnOff, const bool isOn, const int station)
{
    QSqlQuery query;
    query.prepare("insert into OnOffLog(totalOnOff,onOff,id_Station)"
                  "values (?,?,?)");
    query.addBindValue(static_cast<int>(totalOnOff));
    query.addBindValue(static_cast<int>(isOn));
    if(!totalOnOff && station <=0){
        qDebug() << "se intenta insertar en estacion <= 0";
        emit error("se intenta insertar en estacion <= 0");
        return;
    }
    query.addBindValue((!totalOnOff)? station: QVariant(QVariant::Int));
    if(!query.exec()){
        qDebug() << query.lastError();
        emit error(query.lastError().text());
    }
}
