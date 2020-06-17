#ifndef STU_SQLMODEL_H
#define STU_SQLMODEL_H

#if _MSC_VER >= 1600	// MSVC2015 > 1899,	MSVC_VER = 14.0
#pragma execution_character_set("utf-8")
#endif

#include <QObject>
#include <QSqlTableModel>

// 和数据库操作有关
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QSqlRecord>

// 信息提示窗口类头文件
#include <QMessageBox>
#include <QDebug>

#include "network.h"

extern int ex_id;
extern QString ex_pwd;

class Stu_SqlModel : public QObject
{
    Q_OBJECT
public:
    explicit Stu_SqlModel(QObject *parent = nullptr,Network *net = nullptr);
    ~Stu_SqlModel();

    void MainWin_addRecordToTable(double, double, double);  // 外部函数向数据库发送记录
    void MainWin_setHandSubmit(bool flag);

signals:

public slots:


private:
    QSqlDatabase db;
    QSqlQuery query;

public:
    QSqlTableModel *model;

private:
    Network* net;
    void openMysql();
    void putModelToTableView();
};

#endif // STU_SQLMODEL_H
