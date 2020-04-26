#ifndef TABLEVIEW_H
#define TABLEVIEW_H

#include <QTableView>


// 和数据库操作有关
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QSqlTableModel>

// 信息提示窗口类头文件
#include <QMessageBox>
#include <QDebug>

class TableView : public QTableView
{
    Q_OBJECT

public:
    explicit TableView(QWidget *parent = nullptr);
    ~TableView();

private:
    QSqlDatabase db;
    QSqlTableModel *tableModel;


private:
    void openMysql();
    void putModelToTableView();
};

#endif // TABLEVIEW_H
