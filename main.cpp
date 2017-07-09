#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QDebug>
# include "isender.h"
#include "serialsender.h"
int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QGuiApplication app(argc, argv);

    ISender *it ;
    it = new SerialSender();

    //QObject::connect(it,&ISender::msgReceived,[](QString m){qDebug() << "hi" <<m;});
    //QObject::connect(it,&SerialSender::msgReceived,[](QString m){qDebug() << "hi Hi" <<m;});
    QObject::connect(static_cast<SerialSender *>(it),&SerialSender::portNameChanged,[](){qDebug() << "hi hi Hi" ;});
    dynamic_cast<SerialSender *>(it)->setPortName(" puerto ");
    it->sendMsg(" Hola");
    QQmlApplicationEngine engine;
    engine.load(QUrl(QLatin1String("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
