#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QDebug>
#include "isender.h"
#include "serialsender.h"
#include "testsender.h"
#include "productionline.h"
#include <QDebug>
int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QGuiApplication app(argc, argv);
    qmlRegisterType<ISender>();
    qmlRegisterType<SerialSender>("my", 1, 0, "SerialSender");
    ProductionLine  * p = new ProductionLine();
    p->setSender(new TestSender());
    QObject::connect(p,&ProductionLine::error,[](QString m ){qDebug() << "error " + m;});
    QObject::connect(p,&ProductionLine::warning,[](QString m){qDebug() << "warning "+ m;});
    QObject::connect(p,&ProductionLine::log,[](QString m){qDebug() << "log "+ m;});
    QObject::connect(p,&ProductionLine::senderChanged,[](){qDebug() << "senderChanged";});
    QObject::connect(p,&ProductionLine::isStartChanged,[](){qDebug() << "isStartChanged";});
    QObject::connect(p,&ProductionLine::entryOn,[](int from, int to){qDebug() << "entry "+ QString::number( from) +","+ QString::number(to);});
    QObject::connect(p,&ProductionLine::exitOn,[](int from, int to){qDebug() << "exit "+ QString::number( from) +","+ QString::number(to);});

    QObject::connect(p,&ProductionLine::started,[](int i){qDebug() << "started " + QString::number( i);});
    QObject::connect(p,&ProductionLine::stoped,[](int i ){qDebug() << "stopped  "+ QString::number( i);});


    p->start();
    p->stop();
    p->start(-1);
    p->start(2);
    p->stop(-3);
    p->stop(2);
    p->stop(3);


    QQmlApplicationEngine engine;
    engine.load(QUrl(QLatin1String("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
