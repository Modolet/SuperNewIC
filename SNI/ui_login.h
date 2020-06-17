/********************************************************************************
** Form generated from reading UI file 'login.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGIN_H
#define UI_LOGIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Login
{
public:
    QWidget *centralwidget;
    QWidget *layoutWidget;
    QGridLayout *gridLayout;
    QLabel *label;
    QLineEdit *lineEdit_username;
    QLabel *label_2;
    QLineEdit *lineEdit_password;
    QCheckBox *checkBox_autoLogin;
    QCheckBox *checkBox_rememberPwd;
    QPushButton *pushButton_changePasswd;
    QPushButton *pushButton_login;

    void setupUi(QMainWindow *Login)
    {
        if (Login->objectName().isEmpty())
            Login->setObjectName(QString::fromUtf8("Login"));
        Login->resize(205, 126);
        centralwidget = new QWidget(Login);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        layoutWidget = new QWidget(centralwidget);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(20, 10, 165, 99));
        gridLayout = new QGridLayout(layoutWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(layoutWidget);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        lineEdit_username = new QLineEdit(layoutWidget);
        lineEdit_username->setObjectName(QString::fromUtf8("lineEdit_username"));
        lineEdit_username->setMaxLength(9);

        gridLayout->addWidget(lineEdit_username, 0, 1, 1, 2);

        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        lineEdit_password = new QLineEdit(layoutWidget);
        lineEdit_password->setObjectName(QString::fromUtf8("lineEdit_password"));
        lineEdit_password->setMaxLength(15);

        gridLayout->addWidget(lineEdit_password, 1, 1, 1, 2);

        checkBox_autoLogin = new QCheckBox(layoutWidget);
        checkBox_autoLogin->setObjectName(QString::fromUtf8("checkBox_autoLogin"));

        gridLayout->addWidget(checkBox_autoLogin, 2, 0, 1, 2);

        checkBox_rememberPwd = new QCheckBox(layoutWidget);
        checkBox_rememberPwd->setObjectName(QString::fromUtf8("checkBox_rememberPwd"));

        gridLayout->addWidget(checkBox_rememberPwd, 2, 2, 1, 1);

        pushButton_changePasswd = new QPushButton(layoutWidget);
        pushButton_changePasswd->setObjectName(QString::fromUtf8("pushButton_changePasswd"));

        gridLayout->addWidget(pushButton_changePasswd, 3, 0, 1, 2);

        pushButton_login = new QPushButton(layoutWidget);
        pushButton_login->setObjectName(QString::fromUtf8("pushButton_login"));

        gridLayout->addWidget(pushButton_login, 3, 2, 1, 1);

        Login->setCentralWidget(centralwidget);

        retranslateUi(Login);

        QMetaObject::connectSlotsByName(Login);
    } // setupUi

    void retranslateUi(QMainWindow *Login)
    {
        Login->setWindowTitle(QCoreApplication::translate("Login", "MainWindow", nullptr));
        label->setText(QCoreApplication::translate("Login", "\350\264\246\345\217\267", nullptr));
        label_2->setText(QCoreApplication::translate("Login", "\345\257\206\347\240\201", nullptr));
        checkBox_autoLogin->setText(QCoreApplication::translate("Login", "\350\207\252\345\212\250\347\231\273\345\275\225", nullptr));
        checkBox_rememberPwd->setText(QCoreApplication::translate("Login", "\350\256\260\344\275\217\345\257\206\347\240\201", nullptr));
        pushButton_changePasswd->setText(QCoreApplication::translate("Login", "\344\277\256\346\224\271\345\257\206\347\240\201", nullptr));
        pushButton_login->setText(QCoreApplication::translate("Login", "\347\231\273\345\275\225", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Login: public Ui_Login {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGIN_H
