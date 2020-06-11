#include "stu_sqlmodel.h"

Stu_SqlModel::Stu_SqlModel(QObject *parent) : QObject(parent)
{
    openMysql();        // 打开数据库

}

Stu_SqlModel::~Stu_SqlModel()
{
    model->submitAll();        // 最终所有的记录都要上传至数据库当中
}

// 打开数据库
void Stu_SqlModel::openMysql()
{

    // 1.创建一个数据库句柄
    db = QSqlDatabase::addDatabase("QMYSQL");

    // 2.连接数据库
    db.setPort(3306);
    db.setHostName("sni.modolet.xyz");
    db.setUserName("students");                     // 以学生的权限访问
    db.setPassword("metalmax");
    db.setDatabaseName("students");                 // 打开学生的数据库

    query = QSqlQuery(db);                        // 获取当前使用的数据库

    //db.setUserName("students");                     // 以学生的权限访问
    model = new QSqlTableModel(this);
    model->setTable(QString::number(1911101));     // 连接到该学生使用的表
    model->select();                             // 显示tableModel数据

    model->setEditStrategy(QSqlTableModel::OnManualSubmit); // 设置手动提交修改
}

// 把数据库放在tableView里面
void Stu_SqlModel::putModelToTableView()
{
    //tableModel = new QSqlTableModel(this);                  // 创建一个数据库表格模型
    //tableModel->setTable("student");                        // 使用的是哪个表？
    //setModel(tableModel);                                   // 把tableModel放在tableView里面
    //tableModel->select();                                   // 显示tableModel数据
    //setEditTriggers(QAbstractItemView::NoEditTriggers);     // 设置tableView不允许界面修改

    //this->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);   // 设置展示的数据填满表格
}


/******************************************主窗口专用************************************************************/

// 向数据库插入一条记录,并在主窗口的表格里面显示出来，如果要上传至数据库需要手动提交或者在析构函数中提交。
void Stu_SqlModel::MainWin_addRecordToTable(double R0, double R01, double Rx)
{
    qDebug() << "R0:" << R0 << " R01:" << R01 << " Rx:" << Rx;
    QSqlRecord record = model->record();       // 获得表格一条空记录
    record.setValue("R0", R0);
    record.setValue("R0'", R01);
    record.setValue("Rx", Rx);
    int row = model->rowCount();               // 获取目前表格最后一行有记录的行号
    model->insertRecord(row, record);          // 在第一个空行里面插入一条记录
}

// 设置手动提交
void Stu_SqlModel::MainWin_setHandSubmit(bool flag)
{
    if(flag)
        model->setEditStrategy(QSqlTableModel::OnManualSubmit);  // 手动提交
    else
        model->setEditStrategy(QSqlTableModel::OnFieldChange);   // 直接提交至数据库
}
