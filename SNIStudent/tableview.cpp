#include "tableview.h"

TableView::TableView(QWidget *parent) : QTableView(parent)
{
    // 连接数据库并且打开数据库
    openMysql();
    // 把数据库放在tableView里面
    //tableModel = new QSqlTableModel(this);
    putModelToTableView();
}

TableView::~TableView()
{

}

// 打开数据库
void TableView::openMysql()
{
    // 1.创建一个数据库句柄
    db = QSqlDatabase::addDatabase("QMYSQL");

    // 2.连接数据库
    db.setHostName("127.0.0.1");
    db.setUserName("root");
    db.setPassword("sql3835...");
    db.setDatabaseName("stu");

    // 3.打开数据库
    if(!db.open()){
        QMessageBox::warning(this, "错误", db.lastError().text());
        return;
    }
    //else
    //    QMessageBox::warning(this, "错误", "正确");
}

// 把数据库放在tableView里面
void TableView::putModelToTableView()
{
    tableModel = new QSqlTableModel(this);
    // 使用的是哪个表？
    tableModel->setTable("student");
    // 把tableModel放在tableView里面
    setModel(tableModel);
    // 显示tableModel数据
    tableModel->select();
    // 设置tableView不允许界面修改
    setEditTriggers(QAbstractItemView::NoEditTriggers);
}
