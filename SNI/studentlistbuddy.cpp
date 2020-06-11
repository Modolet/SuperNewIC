#include "studentlistbuddy.h"
#include <QPainter>
#include <QFont>
StudentListBuddy::StudentListBuddy(QWidget *parent) : QWidget(parent)
{
    initUi();
}
//初始化UI
void StudentListBuddy::initUi()
{
    //初始化
    name = new QLabel(this);
    id = new QLabel(this);
    sign = new QLabel(this);
    //设置签名字体为灰色
    QPalette color;
    QFont font;
    font.setBold(true);
    color.setColor(QPalette::Text,Qt::gray);
    id->setPalette(color);
    color.setColor(QPalette::Text,Qt::black);
    name->setPalette(color);

    name->setFont(font);
    //布局
    name->move(7,10);
    id->move(7,27);
    sign->move(57,27);

}
