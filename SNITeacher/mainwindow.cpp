#include "mainwindow.h"

#include <QDebug>
#include <QList>
#include "ui_mainwindow.h"
MainWindow::MainWindow(QWidget* parent, network* net)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
    this->setFixedSize(this->width(), this->height());  //固定窗口大小
    this->net = net;
    //获取信息
    getInfo();

//    qDebug() << ex_id;
}

MainWindow::~MainWindow() { delete ui; }

void MainWindow::getInfo()
{
    //获取教师信息
    info sc_info = net->getInfo();
    ui->label_name_2->setText(sc_info.name);
    ui->label_sign->setText(sc_info.sign);
    //获取小组信息
    QList<QString> groupList = net->getGroupList();
    qDebug() << groupList;
    QList<QString>::const_iterator i;
    for(i=groupList.begin();i!=groupList.end();i++)
    {

        ui->studentList->addGroup(*i);
    }
    //获取学生列表
    QList<studentInfo> stuInfoList = net->GetStudentList();
    QList<studentInfo>::const_iterator i_stu;
    for(i_stu = stuInfoList.begin();i_stu != stuInfoList.end();i_stu++)
    {
        qDebug() << (*i_stu).id << (*i_stu).name << (*i_stu).classroom;
        ui->studentList->addStudent(*i_stu);
    }
}
