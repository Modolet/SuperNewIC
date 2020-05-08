#ifndef NETWORK_H
#define NETWORK_H

#include <QObject>
#include <list>
#include <QtNetwork/QTcpSocket>
#include "const.h"

using std::list;

class network : public QObject
{
    Q_OBJECT
public:
    explicit network(QObject *parent = nullptr);
    virtual bool Login(struct TEALogin)=0;
    virtual list<struct studentInfo> GetStudentList()=0;
    virtual bool sendMessage(int stuID,char* message)=0;

signals:
    void connectFailed();

private:
    QTcpSocket socket;
};

#endif // NETWORK_H
