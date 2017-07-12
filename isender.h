#ifndef ISENDER_H
#define ISENDER_H
#include <QString>
#include <QObject>
class ISender:public QObject
{
    Q_OBJECT
public:
    explicit ISender(QObject * parent= nullptr):QObject(parent){

    }
    virtual ~ISender(){}
    virtual void sendMsg(const QString msg)=0;


signals:
    void msgReceived(const QString msg);
    void error(const QString errorMsg);
};

#endif // ISENDER_H
