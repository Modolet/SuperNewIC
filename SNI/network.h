#ifndef NETWORK_H
#define NETWORK_H

#include <QObject>
#include <list>
#include <QtNetwork/QTcpSocket>
#include "const.h"
#include <QSqlDatabase>
#include <QtSql>
#include <QSqlQuery>
#include <QList>
#include <QByteArray>
#include <QVariant>
#include <QSqlTableModel>
#include <QDebug>
#include <QMessageBox>
#include <QString>
#include <QTableView>
#include <QSqlQueryModel>

using std::list;

extern int ex_id;

class network : public QObject
{
    Q_OBJECT
public:
    explicit network(QObject *parent = nullptr);
    bool Login(struct TEALogin);
    QList<struct studentInfo> GetStudentList();
    bool sendMessage(int stuID,char* message);
    bool initSql();
    bool changePwd(int id,QString oldPwd,QString newPwd);
    bool updateIcon(int id,const QByteArray* img,QString format);
    bool updateSign(QString sign);
    bool is_teacher(int id);
    QSqlTableModel* setModel(int id);
    QSqlQueryModel* setDatasModel();
    struct info getInfo(int id = ex_id);
    QList<QString> getGroupList();

signals:
    void connectFailed();

private:
    QTcpSocket socket;
    QSqlDatabase db;
    QSqlQuery sq;
};

#endif // NETWORK_H
