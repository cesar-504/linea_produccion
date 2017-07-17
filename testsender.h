#ifndef TESTSENDER_H
#define TESTSENDER_H

#include <QObject>
#include <QString>
#include <QStringRef>
#include <QDebug>
#include <QTimer>
#include "isender.h"
class TestSender : public ISender
{
    Q_OBJECT
    Q_PROPERTY(QString mode READ mode WRITE setMode NOTIFY modeChanged)
public:
    explicit TestSender(QObject *parent = nullptr): ISender(parent), _mode("normal"){
        _timer = new QTimer(this);
        _timer->setInterval(2000);
        _timer->start();
        connect(_timer,&QTimer::timeout,this,&TestSender::simulation);
    }

    void sendMsg(const QString msg){
        qDebug() << "test; llega " << msg;
        QStringRef ref;
        auto m = msg.trimmed();
        if(!m.startsWith("^") || !m.endsWith("$")){
            emit error("error de formato en comando");
            return;
        }
        m.chop(1);
        m.remove(0,1);

        if(_mode == "normal"){
            if(m.startsWith("00")) return;
            if((m.startsWith("01") || m.startsWith("02")) && QStringRef(&msg,2,2).toInt() >= 0 && QStringRef(&msg,4,2).toInt() >= 0 ){
                qDebug() << "test; se acepta" << msg;
                emit msgReceived("^50"+m+"00$\n");
                return;
            }

        }


    }

    QString mode()const{
        return _mode;
    }
    void setMode(const QString val){
        if(_mode == val) return;
        _mode = val;
        emit modeChanged();
    }

private slots:
    void simulation(){
        if(_exit){
            emit msgReceived("^520"+QString::number(_index) +"0"+QString::number(_index+1) +"$");
            _index++;
        }else
            emit msgReceived("^510"+QString::number(_index-1) +"0"+QString::number(_index) +"$");

        _exit= !_exit;
        if(_index==6) _index=1;


    }

signals:
    void modeChanged();

public slots:
private:
    QString  _mode;
    QTimer * _timer;
    int _index=1;
    bool _exit=false;

};

#endif // TESTSENDER_H
