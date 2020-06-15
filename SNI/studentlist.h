#ifndef STUDENTLIST_H
#define STUDENTLIST_H

#if _MSC_VER >= 1600	// MSVC2015 > 1899,	MSVC_VER = 14.0
#pragma execution_character_set("utf-8")
#endif

#include <QObject>
#include <QListWidget>
#include <QMenu>
#include <QMouseEvent>
#include <QLineEdit>
#include <QFile>
#include <QString>
#include "const.h"
#include "studentexperimentalresult.h"
#include "mainwindow.h"
#include "network.h"

class StudentList : public QListWidget
{
    Q_OBJECT
public:
    explicit StudentList(QWidget *parent = nullptr);
    void mousePressEvent(QMouseEvent *event);//鼠标点击事件
    void contextMenuEvent(QContextMenuEvent*);//菜单事件，为了显示菜单
    void initMenu();//初始化菜单

    QMenu *blankMenu;//点击空白上的菜单
    QMenu *groupMenu;//点击组上的菜单
    QMenu *studentMenu;//点击人上的菜单
    QMap<QListWidgetItem*,QListWidgetItem*> groupMap;   // 组容器 - key:项 value:组
    QMap<QListWidgetItem*,bool> isHideMap;//用来判断该组是否隐藏了
    QLineEdit *groupNameEdit;//组的名字，重命名的时候需要用到
    QListWidgetItem *currentItem;//当前的项
    void setNetwork(Network* net);
private:
    Network* net;
    int id;

signals:

public slots:
    void slotAddGroup();   //添加组
    void addGroup(QString name);       //添加组（内部）
    void slotDelGroup();   //删除组
    void slotRename();     //重命名组
    void slotRenameEditFshed();//命名完成
    void slot_addStudent();//测试用，添加学生
    void addStudent(studentInfo stuInfo);//添加学生
    void slotViewScore();
};

#endif // STUDENTLIST_H
