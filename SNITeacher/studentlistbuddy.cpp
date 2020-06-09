#include "studentlistbuddy.h"
#include <QPainter>
StudentListBuddy::StudentListBuddy(QWidget *parent) : QWidget(parent)
{
    initUi();
}
//初始化UI
void StudentListBuddy::initUi()
{
    //初始化
    name = new QLabel(this);
    sign = new QLabel(this);
    //设置签名字体为灰色
    QPalette color;
    color.setColor(QPalette::Text,Qt::gray);
    sign->setPalette(color);
    //布局
    name->move(7,10);
    sign->move(7,27);

}
