#ifndef LOGIN_H
#define LOGIN_H

#include <QWidget>

#include "const.h"
#include "nettest.h"
#include "mainwindow.h"

namespace Ui {
class Login;
}

struct LoginData
{
    int         userID;
    char        userPWD[16];
    bool        rememberCheck;
    bool        autoLoginCheck;
};

class Login : public QWidget
{
    Q_OBJECT

public:
    explicit Login(QWidget *parent = nullptr);
    ~Login();

signals:
    void signal_login();

private slots:
    void on_autoLogin();

    void on_pushButton_login_clicked();

    void on_checkBox_autoLogin_stateChanged(int arg1);

    void on_lineEdit_username_textEdited(const QString &arg1);

    void on_lineEdit_password_textEdited(const QString &arg1);

    void on_checkBox_rememberPwd_stateChanged(int arg1);



private:
    Ui::Login*          ui;
    struct LoginData    sc_loginData;
    nettest*            socket;
    MainWindow*         mainwindow;

    void ReadLoginData();//读取账号数据
    void WriteLoginData();//写入账号数据
    void AutoLogin();//自动登录
    void SetUerEdit();//自动填充账号栏和密码栏
};

#endif // LOGIN_H
