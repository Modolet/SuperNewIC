﻿#include "studentlist.h"
#include <QAction>
#include <QIcon>
#include <studentlistbuddy.h>
#include <QDebug>

StudentList::StudentList(QWidget *parent) :
    QListWidget(parent)
{
    setFocusPolicy(Qt::NoFocus);                            //去除item选中时的虚线边框
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);   //水平滚动条关闭
    initMenu();
}

//初始化菜单
void StudentList::initMenu()
{
    blankMenu = new QMenu();
    groupMenu = new QMenu();
    studentMenu = new QMenu();
    groupNameEdit = new QLineEdit();
    QAction *viewScore = new QAction("查看学生实验数据",this);
    //设置
    groupNameEdit->setParent(this);               //设置父类
    groupNameEdit->hide();                        //设置初始时隐藏
    groupNameEdit->setPlaceholderText("未命名");   //设置初始时的内容
    //布局
    studentMenu->addAction(viewScore);
    //信息槽
    connect(groupNameEdit,&QLineEdit::editingFinished,this,&StudentList::slotRenameEditFshed);
    connect(viewScore,&QAction::triggered,this,&StudentList::slotViewScore);
}

void StudentList::setNetwork(Network *net)
{
    this->net = net;
}

//添加学生，测试用
void StudentList::slot_addStudent()
{
    StudentListBuddy *buddy=new StudentListBuddy();   //创建一个自己定义的信息类
    buddy->name->setText("Modolet");                  //设置用户名
    buddy->id->setText("刘震没我帅。");   //设置个性签名
    QList<QListWidgetItem*> tem = groupMap.keys(currentItem);//当前组对应的项（包括组本身和好友）复制给tem
    //关键代码
    QListWidgetItem *newItem = new QListWidgetItem();       //创建一个newItem
    this->insertItem(row(currentItem)+tem.count(),newItem); //将该newItem插入到后面
    this->setItemWidget(newItem, buddy); //将buddy赋给该newItem
    groupMap.insert(newItem,currentItem);   //加进容器，key为好友，value为组
    if(isHideMap.value(currentItem))          //如果该组是隐藏，则加进去的好友设置为隐藏
        newItem->setHidden(true);
    else                                      //否则，该好友设置为显示
        newItem->setHidden(false);
}

void StudentList::addStudent(studentInfo stuInfo)
{
    //创建一个自己定义的信息类
    StudentListBuddy *buddy = new StudentListBuddy();
    buddy->name->setText(stuInfo.name);
    buddy->id->setText(QString("%1").arg(stuInfo.id));
    buddy->sign->setText(stuInfo.sign);
    buddy->classroom = stuInfo.classroom;
    buddy->sex = stuInfo.sex;
    //找到对应的组，并设置为currentItem
    for(int j = 0;j < this->count();j++)
    {
        if(stuInfo.classroom == this->item(j)->text())
        {
            currentItem = this->item(j);
        break;
        }
    }
    QList<QListWidgetItem*> tem = groupMap.keys(currentItem);//当前组对应的项（包括组本身和好友）复制给tem
    QListWidgetItem *newItem = new QListWidgetItem();//创建一个newItem
    this->insertItem(row(currentItem)+tem.count(),newItem); //将该newItem插入到后面
    this->setItemWidget(newItem,buddy);//将buddy赋值给newItem
    groupMap.insert(newItem,currentItem);//加进容器，key为好友，value为组
    if(isHideMap.value(currentItem))          //如果该组是隐藏，则加进去的好友设置为隐藏
        newItem->setHidden(true);
    else                                      //否则，该好友设置为显示
        newItem->setHidden(false);
}

void StudentList::slotViewScore()
{
    StudentExperimentalResult* m_SER;
    m_SER = new StudentExperimentalResult(this,net,id);
    m_SER->show();
}

//鼠标点击事件
void StudentList::mousePressEvent(QMouseEvent *event)
{
    QListWidget::mousePressEvent(event);                            // 如果不调用基类mousePressEvent，item被select会半天不响应,调用父类，让QSS起效，因为QSS基于父类QListWidget，子类就是子窗口，就是最上层窗口，是覆盖在父窗口上的，所以先于父窗口捕获消息
    //防止一种特殊情况：给新item命名、点击其他item或空白处时，指向新item的currentItem被赋予其他item
    if(groupNameEdit->isVisible() && !(groupNameEdit->rect().contains(event->pos())))
        {
            if(groupNameEdit->text()!=NULL)
                currentItem->setText(groupNameEdit->text());
            groupNameEdit->setText("");
            groupNameEdit->hide();
        }
    currentItem = this->itemAt(mapFromGlobal(QCursor::pos()));          //鼠标位置的Item，不管右键左键都获取
    if(event->button()==Qt::LeftButton && currentItem!=NULL && currentItem==groupMap.value(currentItem))//如果点击的左键并且是点击的是组
    {
        if(isHideMap.value(currentItem))                                  //如果先前是隐藏，则显示
        {
            foreach(QListWidgetItem* subItem, groupMap.keys(currentItem))//遍历组的对应的项（包括自身和好友）
                if(subItem!=currentItem)                                 //如果是组的话不进行处理
                {
                    subItem->setHidden(false);                            //好友全部显示
                }
            isHideMap.insert(currentItem,false);                          //设置该组为显示状态
            currentItem->setIcon(QIcon(":/arrowDown"));
        }
        else                                                             //否则，先前是显示，则隐藏
        {
            foreach(QListWidgetItem* subItem, groupMap.keys(currentItem))//遍历组的对应的项（包括自身和好友）
                if(subItem!=currentItem)                                 //如果是组的话不进行处理
                {
                    subItem->setHidden(true);                            //好友全部隐藏
                }
             isHideMap.insert(currentItem,true);                          //设置该组为隐藏状态
             currentItem->setIcon(QIcon(":/arrowRight"));
        }
    }
}


//菜单事件
void StudentList::contextMenuEvent(QContextMenuEvent *event)
{
    QListWidget::contextMenuEvent(event);                                   //调用基类事件
    if(currentItem == NULL)                                                 //如果点击到的是空白处
    {
        blankMenu->exec(QCursor::pos());
        return;
    }
    if(currentItem == groupMap.value(currentItem))
        groupMenu->exec(QCursor::pos());
    else                                                                    //否则点击到的是好友
    {
        QWidget* pwig = this->itemWidget(currentItem);
        QList<QLabel*> label = pwig->findChildren<QLabel*>();
        id = label[1]->text().toInt();
        studentMenu->exec(QCursor::pos());
    }

}

//添加组
void StudentList::slotAddGroup()
{
    QListWidgetItem *newItem = new QListWidgetItem(QIcon(":/arrowRight"),"未命名");
    newItem->setSizeHint(QSize(this->width(),25));                          //设置宽度，高度
    this->addItem(newItem);//加到QListWidget中
    groupMap.insert(newItem,newItem);                                       //加到容器groupMap里，key和value都为组
    isHideMap.insert(newItem,true);                                         //设置该组为隐藏状态
    groupNameEdit->raise();
    groupNameEdit->setText(tr("未命名"));                                    //设置默认内容
    groupNameEdit->selectAll();                                             //设置全选
    groupNameEdit->setGeometry(this->visualItemRect(newItem).left()+15,this->visualItemRect(newItem).top()+1,this->visualItemRect(newItem).width(),this->visualItemRect(newItem).height()-2);//出现的位置
    groupNameEdit->show();                                                  //显示
    groupNameEdit->setFocus();                                              //获取焦点
    currentItem = newItem;                                                  // 因为要给group命名，所以当前的currentItem设为该group
}

void StudentList::addGroup(QString name)
{
    QListWidgetItem * newItem = new QListWidgetItem(QIcon(":/arrowRight"),name);
    newItem->setSizeHint(QSize(this->width(),25));
    this->addItem(newItem);
    groupMap.insert(newItem,newItem);
    isHideMap.insert(newItem,true);
}

//删除组
void StudentList::slotDelGroup()
{
    foreach(QListWidgetItem* item,groupMap.keys(currentItem))               //遍历该组的所有好友和自身的组
    {
        groupMap.remove(item);                                              //移除
        delete item;                                                        //删除
    }
    isHideMap.remove(currentItem);                                          //移除
}

//重命名
void StudentList::slotRename()
{
    groupNameEdit->raise();
    groupNameEdit->setGeometry(this->visualItemRect(currentItem).left()+15,this->visualItemRect(currentItem).top()+1,this->visualItemRect(currentItem).width(),this->visualItemRect(currentItem).height()-2);//出现的位置
    groupNameEdit->setText(currentItem->text());                            //获取该组名内容
    groupNameEdit->show();                                                  //显示
    groupNameEdit->selectAll();                                             //全选
    groupNameEdit->setFocus();                                              //获取焦点
}

//重命名完成
void StudentList::slotRenameEditFshed()
{
    if(groupNameEdit->text()!=NULL)                                         //如果重命名编辑框不为空
        currentItem->setText(groupNameEdit->text());                        //更新组名
    groupNameEdit->setText("");
    groupNameEdit->hide();                                                  //隐藏重命名编辑框
}
