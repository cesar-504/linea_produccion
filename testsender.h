#ifndef TESTSENDER_H
#define TESTSENDER_H

#include <QObject>
#include <QString>
#include <QStringRef>
#include <QDebug>
#include <QTimer>
#include "isender.h"
#include <random>
class TestSender : public ISender
{
    Q_OBJECT
    Q_PROPERTY(QString mode READ mode WRITE setMode NOTIFY modeChanged)
public:
    explicit TestSender(QObject *parent = nullptr): ISender(parent), _mode("normal"){
        _timer = new QTimer(this);
        _timer->setInterval(700);
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
                if(m.startsWith("01"))
                    _timer->start();
                else
                    _timer->stop();

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
            std::mt19937 eng(rd()); // seed the generator
            std::uniform_int_distribution<> distr(1, 100); // define the range
            if(_index == 3 && distr(eng) >60){
                 emit msgReceived("^520"+QString::number(_index) +"0"+QString::number(6) +"$");
                _from=_index;
                _index=6;

            }else if(_index == 7 && distr(eng) >30){
                emit msgReceived("^520"+QString::number(_index) +"0"+QString::number(2) +"$");
               _from=_index;
               _index=2;
            }else{
                emit msgReceived("^520"+QString::number(_index) +"0"+QString::number(_index+1) +"$");
                _index++;
                _from=-1;
                if(_index==6 || _index==10){ _index=1; _from=-1;}

            }


        }else{
            if(_from<0)
                emit msgReceived("^510"+QString::number(_index-1) +"0"+QString::number(_index) +"$");
            else
                emit msgReceived("^510"+QString::number(_from) +"0"+QString::number(_index) +"$");
        }
        _exit= !_exit;



    }

    void startStop(bool b){
        isStart = b;
        if(b)
            _timer->start();
        else
            _timer->stop();

    }

signals:
    void modeChanged();

public slots:
private:
    QString  _mode;
    QTimer * _timer;
    int _index=1;
    int _from=-1;
    bool _exit=false;

    bool isStart=false;
    std::random_device rd;

};

#endif // TESTSENDER_H
