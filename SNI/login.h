#ifndef LOGIN_H
#define LOGIN_H

#if _MSC_VER >= 1600	// MSVC2015 > 1899,	MSVC_VER = 14.0
#pragma execution_character_set("utf-8")
#endif

#include <QMainWindow>

#include "changepasswd.h"
#include "const.h"
#include "mainwindow.h"
#include "stu_mainwindow.h"
#include "first.h"
#include "network.h"

extern int ex_id;
namespace Ui {
class Login;
}

struct LoginData {
    int userID;
    char userPWD[16];
    bool rememberCheck;
    bool autoLoginCheck;
};

class Login : public QMainWindow {
    Q_OBJECT

public:
    explicit Login(QWidget* parent = nullptr);
    ~Login();

signals:
    void signal_login();

private slots:
    void on_autoLogin();

    void on_pushButton_login_clicked();

    void on_checkBox_autoLogin_stateChanged(int arg1);

    void on_lineEdit_username_textEdited(const QString& arg1);

    void on_lineEdit_password_textEdited(const QString& arg1);

    void on_checkBox_rememberPwd_stateChanged(int arg1);

    void on_pushButton_changePasswd_clicked();

    void login(bool);           //登录

    void NetErr();

private:
    Ui::Login* ui;
    struct LoginData sc_loginData;
    struct TEALogin sc_TEALogin;
    Network* net;
    MainWindow* mainwindow;
    changePasswd* cpwd;
    First* first;

    void ReadLoginData();   //读取账号数据
    void WriteLoginData();  //写入账号数据
    void AutoLogin();       //自动登录
    void SetUerEdit();      //自动填充账号栏和密码栏


};

#endif  // LOGIN_H
