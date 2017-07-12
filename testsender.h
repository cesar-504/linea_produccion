#ifndef TESTSENDER_H
#define TESTSENDER_H

#include <QObject>
#include <QString>
#include <QStringRef>
#include <QDebug>
#include "isender.h"
class TestSender : public ISender
{
    Q_OBJECT
    Q_PROPERTY(QString mode READ mode WRITE setMode NOTIFY modeChanged)
public:
    explicit TestSender(QObject *parent = nullptr): ISender(parent), _mode("normal"){

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

signals:
    void modeChanged();

public slots:
private:
    QString  _mode;


};

#endif // TESTSENDER_H
