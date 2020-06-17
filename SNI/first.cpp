#include "first.h"
#include "ui_first.h"

First::First(QWidget *parent,int id,Network* net) :
    QWidget(parent),
    ui(new Ui::First)
{
    ui->setupUi(this);
    this->net = net;
    this->id = id;
    this->parent = parent;
    initUI();
}

void First::initUI()
{
    this->setWindowFlag(Qt::Window);
    this->setWindowTitle("账户验证");
    this->setFixedSize(this->size());
    this->ui->lineEdit_ID->setText(QString::number(id));
}

First::~First()
{
    delete ui;
}

void First::on_pushButton_getVcode_clicked()
{
    QString email = ui->lineEdit_email->text();
    QString id = ui->lineEdit_ID->text();
    QString pwd = ui->lineEdit_pwd->text();
    QByteArray ba_pwd;
    QByteArray pwdhash;
    ba_pwd.append(pwd);
    pwdhash = QCryptographicHash::hash(ba_pwd,QCryptographicHash::Sha256);
    QRegExp reEmail("^([A-Za-z0-9_\\-\\.])+\\@([A-Za-z0-9_\\-\\.])+\\.([A-Za-z]{2,4})$");
    QRegExp reId("[0-9]{5,7}");
    if(reEmail.exactMatch(email))
    {
        if(!reId.exactMatch(id))
        {
            QMessageBox::warning(this,"错误！","请输入正确的ID！");
            return;
        }
        if(!reEmail.exactMatch(email))
        {
            QMessageBox::warning(this,"错误！","请输入正确的邮箱！");
            return;
        }
        net->sendMsg(QString("xyxyxc#%1#ID:_d_%2_d_,email:_d_%3_d_,xyxyxcend").arg(e_Vcode).arg(id).arg(email));
        QMessageBox::information(this,"提示","邮件已发送到您的邮箱！如果未找到，请检查你的邮件垃圾箱！");
    }
}

void First::closeEvent(QCloseEvent *event)
{
    this->close();
    parent->show();
}

void First::on_pushButton_OK_clicked()
{
    QString email = ui->lineEdit_email->text();
    QString id = ui->lineEdit_ID->text();
    QString pwd = ui->lineEdit_pwd->text();
    QString vcode = ui->lineEdit_Vcode->text();
    QByteArray ba_pwd;
    QByteArray pwdhash;
    QRegExp rePwd("^(?![A-Z]+$)(?![a-z]+$)(?!\\d+$)(?![\\W_]+$)\\S{6,16}$");
    if(!rePwd.exactMatch(pwd))
    {
        QMessageBox::warning(this,"提示","密码太弱！\n至少8-16个字符，至少包含小写字母、大写字母、数字、特殊符号的两种及以上");
        return ;
    }
    ba_pwd.append(pwd);
    pwdhash = QCryptographicHash::hash(ba_pwd,QCryptographicHash::Sha256);
    net->sendMsg(QString("xyxyxc#%1#ID:_d_%2_d_,email:_d_%3_d_,code:_d_%4_d_,hash:_d_%5_d_,pwd:_d_%6_d_,xyxyxcend").arg(e_RegisterComparedTheCode).arg(id).arg(email).arg(vcode).arg(pwdhash.toHex().toStdString().c_str()).arg(pwd));
    if(net->RegisterComparedTheCode())
    {
        QMessageBox::information(this,"提示","绑定成功！请牢记您的密码");
        this->close();
        parent->show();
    }
    else
    {
        QMessageBox::information(this,"错误","请检查你的邮箱、id和密码");
    }
}
















