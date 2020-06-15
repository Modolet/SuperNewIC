﻿#include "network.h"

Network::Network(QObject *parent) : QObject(parent) 
{
    initSql(); 
    code = new QString;
    socket = new QTcpSocket();
    socket->connectToHost("127.0.0.1",4361);

    if(!connect(socket,&QTcpSocket::readyRead,this,&Network::RecvMsg))
    {
        QMessageBox::warning(nullptr,"错误！","连接服务器失败！");
    }
}

bool Network::Login(TEALogin sc_tea) {
    socket->write(QString("xyxyxc#%1#ID:_d_userid_d_xyxyxcend").arg(e_IsTea).toLatin1());
    db.setUserName(QString::number(sc_tea.userID));
    db.setPassword(QString(sc_tea.userPWD));
    db.setDatabaseName("students");
    //打开数据库
    if (!db.open()) {
      QMessageBox::warning(NULL, "错误", db.lastError().text());
      return false;
    }
    else
    {
        //获取数据库操作类
        sq = QSqlQuery(db);
        delete code;
        return true;
    }
}

QList<studentInfo> Network::GetStudentList()
{
    QList<studentInfo> info;
    if(!sq.exec("select id,name,class,sex,sign from datas where is_teacher is null"))
    {
         QMessageBox::warning(NULL, "错误！", "数据交互出现错误：-1");
         return info;
    }
    while(sq.next())
    {
        info.push_back({sq.value("id").toInt(),
                        sq.value("name").toString(),
                        sq.value("class").toString(),
                        sq.value("sign").toString(),
                        sq.value("sex").toString()});
    }
    return info;
}

void Network::initSql() {
  //添加数据库驱动
  db = QSqlDatabase::addDatabase("QMYSQL");
  //设置数据库
  db.setPort(3306);
  db.setHostName("sni.modolet.xyz");
}

bool Network::changePwd(int id, QString oldPwd, QString newPwd) {
  if (!sq.exec(QString("select passwd from datas where id=%1").arg(id))) {
    QMessageBox::warning(NULL, "错误！", "数据交互出现错误：-1");
    return false;
  } else {
    sq.next();
    if (sq.value(0) == oldPwd) {
      if (!sq.exec(QString("update datas set passwd=\"%1\" where id=%2")
                       .arg(newPwd)
                       .arg(id))) {
        QMessageBox::warning(NULL, "错误！", "数据交互出现错误：-2");
        return false;
      } else
        return true;
    } else
      return false;
  }
}

bool Network::updateIcon(int id, const QByteArray *img, QString format)
{
    sq.prepare("update datas set image=?,format=? where id=?");
    sq.addBindValue(QVariant(*img));
    sq.addBindValue(format);
    sq.addBindValue(id);
    if(sq.exec())
        return true;
    else
        return false;
}

bool Network::updateSign(QString sign)
{
    if(sq.exec(QString("update datas set sign='%1' where id=%2").arg(sign).arg(ex_id)))
        return true;
    return false;
}

bool Network::is_teacher(int id)
{
    QTime delayTime = QTime::currentTime().addMSecs(5000);
    while(QTime::currentTime() < delayTime)
    {
        QCoreApplication::processEvents(QEventLoop::AllEvents, 5);
        if(rc_IsTea)break;
    }
    rc_IsTea = false;
    return rs_IsTea;
}

bool Network::RegisterComparedTheCode()
{
    QTime delayTime = QTime::currentTime().addMSecs(5000);
    while(QTime::currentTime() < delayTime)
    {
        QCoreApplication::processEvents(QEventLoop::AllEvents, 5);
        if(rc_RegisterComparedTheCode)break;
    }
    rc_RegisterComparedTheCode = false;
    return rs_RegisterComparedTheCode;
}

bool Network::IsHave()
{
    QTime delayTime = QTime::currentTime().addMSecs(5000);
    while(QTime::currentTime() < delayTime)
    {
        QCoreApplication::processEvents(QEventLoop::AllEvents, 5);
        if(rc_IsHave)break;
    }
    rc_IsHave = false;
    return rs_IsHave;
}

bool Network::IsReg()
{
    QTime delayTime = QTime::currentTime().addMSecs(5000);
    while(QTime::currentTime() < delayTime)
    {
        QCoreApplication::processEvents(QEventLoop::AllEvents, 5);
        if(rc_IsReg)break;
    }
    rc_IsReg = false;
    return rs_IsReg;
}

void Network::sendMsg(QString msg)
{
    socket->write(QByteArray().append(msg));
    qDebug() << "send:" + msg;
}

QSqlDatabase Network::getDB()
{
    return db;
}

QSqlQuery Network::getSQ()
{
    return sq;
}

QSqlTableModel *Network::setModel(int id)
{
    QSqlTableModel* model = new QSqlTableModel(this);
    model->setTable(QString::number(id));
    model->setEditStrategy(QSqlTableModel::OnManualSubmit);
    model->select();

    return model;
}

QSqlQueryModel *Network::setDatasModel()
{
    QSqlQueryModel* model = new QSqlQueryModel();
    model->setQuery(sq);
    return model;
}

info Network::getInfo(int id)
{
    if(!sq.exec(QString("select name,sign,image,format,score from datas where id=%1;").arg(id)))
    {
        QMessageBox::warning(NULL, "错误", db.lastError().text());
        return {0,0};
    }
    sq.next();
    return {sq.value(0).toString(),sq.value(1).toString(),sq.value("image").toByteArray(),sq.value("format").toString(),sq.value("score").toInt()};
}

QList<QString> Network::getGroupList()
{
    QList<QString> ret;
    if(!sq.exec("select distinct class from datas where is_teacher is null and class is not null"))
    {
        QMessageBox::warning(NULL, "错误", db.lastError().text());
        return {0};
    }
    while (sq.next()) {
        ret.push_back(sq.value(0).toString());
    }
    return ret;
}

void Network::RecvMsg()
{
    QByteArray byteArray = this->socket->readAll();
    QString msg(byteArray);
    qDebug() << "recv:" + msg;
    if(msg.size())is_Recv = true;
    if(msg == "xyxyxc#GetHash#_d_HashTrue_d_,xyxyxcend")
    {
        rs_GetHash = true;
        rc_GetHash = true;
    }
    else if(msg == "xyxyxc#getHash#_d_HashFalse_d_,xyxyxcend")
    {
        rs_GetHash = false;
        rc_GetHash = true;
    }
    else if(msg == "xyxyxc#ComparedTheCode#result:_d_True_d_,xyxyxcend")
    {
        rs_RegisterComparedTheCode = true;
        rc_RegisterComparedTheCode = true;
    }
    else if(msg == "xyxyxc#ComparedTheCode#result:_d_False_d_,xyxyxcend")
    {
        rs_RegisterComparedTheCode = false;
        rc_RegisterComparedTheCode = true;
    }
    else if(msg == "xyxyxc#IsReg#result:_d_True_d_,xyxyxcend")
    {
        rs_IsReg = true;
        rc_IsReg = true;
    }
    else if(msg == "xyxyxc#IsReg#result:_d_False_d_,xyxyxcend")
    {
        rs_IsReg = false;
        rc_IsReg = true;
    }
    else if(msg == "xyxyxc#IsTea#result:_d_True_d_,xyxyxcend")
    {
        rs_IsTea = true;
        rc_IsTea = true;
    }
    else if(msg == "xyxyxc#IsTea#result:_d_False_d_,xyxyxcend")
    {
        rs_IsTea = false;
        rc_IsTea = true;
    }
    else if(msg == "xyxyxc#IsHave#result:_d_True_d_,xyxyxcend")
    {
        rs_IsHave = true;
        rc_IsHave = true;
    }
    else if(msg == "xyxyxc#IsHave#result:_d_False_d_,xyxyxcend")
    {
        rs_IsHave = false;
        rc_IsHave = true;
    }
}











