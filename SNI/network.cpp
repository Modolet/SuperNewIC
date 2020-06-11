#include "network.h"


network::network(QObject *parent) : QObject(parent) { initSql(); }

bool network::Login(TEALogin sc_tea) {
  if (!sq.exec(QString("select passwd,is_teacher from datas where id=%1")
                   .arg(sc_tea.userID))) {
    QMessageBox::warning(NULL, "错误！", "数据交互出现错误：-1");
  }
  //获取数据
  sq.next();
  if (sq.value(0) == QString(sc_tea.userPWD))  //密码正确
    return true;
  else  //密码错误
    return false;
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

bool network::updateIcon(int id, const QByteArray *img, QString format)
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

bool network::updateSign(QString sign)
{
    if(sq.exec(QString("update datas set sign='%1' where id=%2").arg(sign).arg(ex_id)))
        return true;
    return false;
}

bool network::is_teacher(int id)
{
    sq.exec(QString("select is_teacher from datas where id=%1").arg(id));
    sq.next();
    qDebug() << sq.value(0);
    if(sq.value(0).toInt() == 1)
        return true;
    return false;
}

QSqlTableModel *network::setModel(int id)
{
    QSqlTableModel* model = new QSqlTableModel(this);
    model->setTable(QString::number(id));
    model->setEditStrategy(QSqlTableModel::OnManualSubmit);
    model->select();

    return model;
}

QSqlQueryModel *network::setDatasModel()
{
    QSqlQueryModel* model = new QSqlQueryModel();
    model->setQuery(sq);
    return model;
}

info network::getInfo(int id)
{
    if(!sq.exec(QString("select name,sign,image,format,score from datas where id=%1;").arg(id)))
    {
        QMessageBox::warning(NULL, "错误", db.lastError().text());
        return {0,0};
    }
    sq.next();
    return {sq.value(0).toString(),sq.value(1).toString(),sq.value("image").toByteArray(),sq.value("format").toString(),sq.value("score").toInt()};
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
