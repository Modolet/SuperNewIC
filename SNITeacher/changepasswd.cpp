#include "changepasswd.h"
#include "ui_changepasswd.h"
#include <QMessageBox>
changePasswd::changePasswd(QWidget *parent, int id,network* net) :
    QWidget(parent),
    ui(new Ui::changePasswd)
{
    ui->setupUi(this);
    ui->lineEdit_id->setText(QString("%1").arg(id));//自动读取用户id
    this->net = net;
    this->id = id;
    this->parent = parent;
    ui->lineEdit_id->setValidator(new QIntValidator(0,999999999,this));//确保只能输入整数
    ui->lineEdit_old_passwd->setEchoMode(QLineEdit::Password);//确保密码行不显示输入的内容
    ui->lineEdit_new_passwd->setEchoMode(QLineEdit::Password);//确保密码行不显示输入的内容
    this->setFixedSize(this->width(),this->height());//固定窗口大小
}

changePasswd::~changePasswd()
{
    delete ui;
}

void changePasswd::closeEvent(QCloseEvent *event)
{
    parent->show();
}

void changePasswd::on_pushButton_ok_clicked()
{
    if(net->changePwd(id,ui->lineEdit_old_passwd->text(),ui->lineEdit_new_passwd->text()))
    {
        QMessageBox::information(this,"通知","修改密码成功！");
        parent->show();
        this->close();
    }
    else
    {
        QMessageBox::warning(this,"错误","请检查您的旧密码是否正确！");
    }
}
