﻿#include "login.h"

#include <string.h>

#include <QDebug>
#include <QFile>
#include <QIntValidator>
#include <QMessageBox>

#include "mainwindow.h"
#include "ui_login.h"

Login::Login(QWidget *parent) : QMainWindow(parent), ui(new Ui::Login) {
    ui->setupUi(this);
    ui->lineEdit_username->setValidator(
                new QIntValidator(0, 999999999, this));  //确保只能输入整数
    ui->lineEdit_password->setEchoMode(
                QLineEdit::Password);  //确保密码行不显示输入的内容
    this->setFixedSize(this->width(), this->height());  //固定窗口大小
    this->setWindowTitle("登录");                       //窗口标题
    sc_loginData = {0};                                 //初始化登录数据
    net = new Network;

    //下面是信号和槽==============================================================================
    connect(this, &Login::signal_login, this, &Login::on_autoLogin);
    //connect(net->socket,&QTcpSocket::errorOccurred,this,&Login::NetErr);

    SetUerEdit();  //读取并初始化界面
    this->show();
    if (ui->checkBox_autoLogin->isChecked() == true) {
        emit(signal_login());  //如果选择了自动登录，就发出登录信号
    }
}

Login::~Login() { delete ui; }

void Login::on_autoLogin() { AutoLogin(); }

void Login::on_pushButton_login_clicked() { AutoLogin(); }

void Login::on_checkBox_autoLogin_stateChanged(int arg1) {
    if (arg1 == 2)  //勾选自动登录的时候，自动勾选记住密码
    {
        ui->checkBox_rememberPwd->setCheckState(Qt::CheckState::Checked);
        sc_loginData.rememberCheck = true;
        sc_loginData.autoLoginCheck = true;
    } else {
        sc_loginData.autoLoginCheck = false;
    }
    WriteLoginData();
}

void Login::ReadLoginData() {
    QFile f_loginData("data");
    if (!f_loginData.open(QIODevice::ReadOnly)) return;
    char c1;
    for (int i = 0; f_loginData.read(&c1, 1); i++) {
        ((char *)&sc_loginData)[i] = c1 ^ 0xF1;
    }
    f_loginData.close();
}

void Login::WriteLoginData() {
    QFile f_loginData("data");
    char c;
    if (!f_loginData.open(QIODevice::WriteOnly)) return;
    for (int i = 0; i < sizeof(sc_loginData); i++) {
        c = ((char *)&sc_loginData)[i] ^ 0xF1;
        f_loginData.write(&c, 1);
    }
    f_loginData.close();
}

void Login::AutoLogin() {
    sc_TEALogin.userID = ui->lineEdit_username->text().toInt();
    strcpy_s(sc_TEALogin.userPWD,
           ui->lineEdit_password->text().toStdString().c_str());
    net->sendMsg(QString("xyxyxc#%1#ID:_d_%2_d_xyxyxcend").arg(e_IsHave).arg(QString::number(sc_TEALogin.userID)));
    if(net->IsHave())
    {
        net->sendMsg(QString("xyxyxc#%1#ID:_d_%2_d_xyxyxcend").arg(e_IsReg).arg(QString::number(sc_TEALogin.userID)));
        login(net->IsReg());
    }
    else
        QMessageBox::warning(this,"警告","账号不存在！");
}

void Login::SetUerEdit() {
    ReadLoginData();
    if (sc_loginData.rememberCheck)
        ui->checkBox_rememberPwd->setCheckState(Qt::CheckState::Checked);
    if (sc_loginData.autoLoginCheck)
        ui->checkBox_autoLogin->setCheckState(Qt::CheckState::Checked);
    if (sc_loginData.userID)
        ui->lineEdit_username->setText(
                    QString::number(sc_loginData.userID));  //读取用户名
    if (ui->checkBox_rememberPwd->isChecked())    //选择读取密码
        ui->lineEdit_password->setText(sc_loginData.userPWD);
    return;
}

void Login::NetErr()
{
    QMessageBox::warning(this,"错误","与服务器的连接出现错误！程序将退出");
    exit(-1);
}

void Login::login(bool is_reg)
{
    if(is_reg)
    {
        if (net->Login(sc_TEALogin)) {
            if(net->is_teacher(sc_TEALogin.userID))
            {
            ex_id = sc_TEALogin.userID;
            mainwindow = new MainWindow(NULL, net);
            this->close();
            mainwindow->show();
            mainwindow->setWindowTitle("超新芯");
            }
            else
            {
                qDebug() << "student";
                ex_id = sc_TEALogin.userID;
                ex_pwd = sc_TEALogin.userPWD;
                Stu_MainWindow* stu = new Stu_MainWindow(nullptr,net);
                stu->show();
                this->close();
            }

        } else {
            QMessageBox::information(this, "错误", "账号或密码错误");
        }
    }
    else
    {
        QMessageBox::information(this,"提示","初次使用，请验证账号！");
        first = new First(this,sc_TEALogin.userID,net);
        this->hide();
        first->show();
    }
}

void Login::on_lineEdit_username_textEdited(const QString &arg1) {
    sc_loginData.userID = arg1.toInt();
    WriteLoginData();
}

void Login::on_lineEdit_password_textEdited(const QString &arg1) {
    ::strcpy(sc_loginData.userPWD, arg1.toStdString().c_str());
    WriteLoginData();
}

void Login::on_checkBox_rememberPwd_stateChanged(int arg1) {
    switch (arg1) {
    case 0:
        memset(sc_loginData.userPWD, 0, sizeof(sc_loginData.userPWD));
        sc_loginData.rememberCheck = false;
        break;
    case 2:
        sc_loginData.rememberCheck = true;
        break;
    }
    WriteLoginData();
}

void Login::on_pushButton_changePasswd_clicked() {
    this->hide();
    cpwd = new changePasswd(this, sc_loginData.userID, net);
    cpwd->setWindowFlag(Qt::Window);

    cpwd->show();
    cpwd->setWindowTitle(QString("您正在修改密码"));
}
