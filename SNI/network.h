#ifndef NETWORK_H
#define NETWORK_H

#if _MSC_VER >= 1600	// MSVC2015 > 1899,	MSVC_VER = 14.0
#pragma execution_character_set("utf-8")
#endif

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
#include <QTime>


//#include "login.h"

using std::list;

extern int ex_id;

class Network
        : public QObject
{
    Q_OBJECT
public:

    QTcpSocket* socket;
    QString* code;
    explicit Network(QObject *parent = nullptr);
    bool Login(struct TEALogin);
    QList<struct studentInfo> GetStudentList();
    bool sendMessage(int stuID,char* message);
    void initSql();
    bool changePwd(int id,QString oldPwd,QString newPwd);
    bool updateIcon(int id,const QByteArray* img,QString format);
    bool updateSign(QString sign);
    bool is_teacher(int id);
    bool RegisterComparedTheCode();
    bool IsHave();
    bool IsReg();
    void sendMsg(QString msg);
    QSqlDatabase getDB();
    QSqlQuery getSQ();
    QSqlTableModel* setModel(int id);
    QSqlQueryModel* setDatasModel();
    struct info getInfo(int id = ex_id);
    QList<QString> getGroupList();

public slots:
    void RecvMsg();
signals:

private:
    QSqlDatabase db;
    QSqlQuery sq;
    bool rs_IsHave = false;
    bool rs_RegisterComparedTheCode = false;
    bool rs_Vcode = false;
    bool rs_GetHash = false;
    bool rs_IsReg = false;
    bool rs_IsTea = false;

    bool rc_IsHave = false;
    bool rc_RegisterComparedTheCode = false;
    bool rc_Vcode = false;
    bool rc_GetHash = false;
    bool rc_IsReg = false;
    bool rc_IsTea = false;

    bool is_Recv = false;
};

#endif // NETWORK_H
