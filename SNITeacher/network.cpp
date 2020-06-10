#include "network.h"

#include <QDebug>
#include <QMessageBox>
#include <QString>
network::network(QObject *parent) : QObject(parent) { initSql(); }

bool network::Login(TEALogin sc_tea) {
  if (!sq.exec(QString("select passwd,is_teacher from datas where id=%1")
                   .arg(sc_tea.userID))) {
    QMessageBox::warning(NULL, "错误！", "数据交互出现错误：-1");
  }
  //获取数据
  sq.next();
//  qDebug() << sq.value(1);
  if (sq.value(1) != 1) {
    QMessageBox::warning(nullptr, "错误！", "请使用教师账号登录！");
    return false;
  }
  if (sq.value(0) == QString(sc_tea.userPWD))  //密码正确
    return true;
  else  //密码错误
  {
    return false;
  }
}

QList<studentInfo> network::GetStudentList()
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
        //qDebug() << sq.value(0) << sq.value(1) << sq.value(2);
    }
    return info;
}

bool network::initSql() {
  //添加数据库驱动
  db = QSqlDatabase::addDatabase("QMYSQL");
  //设置数据库
  db.setPort(3306);
  db.setHostName("sni.modolet.xyz");
  db.setUserName("teacher");
  db.setPassword("metalmax");
  db.setDatabaseName("students");
  //打开数据库
  if (!db.open()) {
    QMessageBox::warning(NULL, "错误", db.lastError().text());
    return false;
  }
  //获取数据库操作类
  sq = QSqlQuery(db);
}

bool network::changePwd(int id, QString oldPwd, QString newPwd) {
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

info network::getInfo()
{
    if(!sq.exec(QString("select name,sign from datas where id=%1;").arg(ex_id)))
    {
        QMessageBox::warning(NULL, "错误", db.lastError().text());
        return {0,0};
    }
    sq.next();
    return {sq.value(0).toString(),sq.value(1).toString()};
}

QList<QString> network::getGroupList()
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
