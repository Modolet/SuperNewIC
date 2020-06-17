/********************************************************************************
** Form generated from reading UI file 'changepasswd.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHANGEPASSWD_H
#define UI_CHANGEPASSWD_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_changePasswd
{
public:
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout;
    QLabel *label;
    QLineEdit *lineEdit_id;
    QLabel *label_2;
    QLineEdit *lineEdit_old_passwd;
    QLabel *label_3;
    QLineEdit *lineEdit_new_passwd;
    QPushButton *pushButton_ok;

    void setupUi(QWidget *changePasswd)
    {
        if (changePasswd->objectName().isEmpty())
            changePasswd->setObjectName(QString::fromUtf8("changePasswd"));
        changePasswd->resize(260, 131);
        widget = new QWidget(changePasswd);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(40, 10, 179, 105));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label = new QLabel(widget);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        lineEdit_id = new QLineEdit(widget);
        lineEdit_id->setObjectName(QString::fromUtf8("lineEdit_id"));

        gridLayout->addWidget(lineEdit_id, 0, 1, 1, 1);

        label_2 = new QLabel(widget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        lineEdit_old_passwd = new QLineEdit(widget);
        lineEdit_old_passwd->setObjectName(QString::fromUtf8("lineEdit_old_passwd"));

        gridLayout->addWidget(lineEdit_old_passwd, 1, 1, 1, 1);

        label_3 = new QLabel(widget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 2, 0, 1, 1);

        lineEdit_new_passwd = new QLineEdit(widget);
        lineEdit_new_passwd->setObjectName(QString::fromUtf8("lineEdit_new_passwd"));

        gridLayout->addWidget(lineEdit_new_passwd, 2, 1, 1, 1);


        verticalLayout->addLayout(gridLayout);

        pushButton_ok = new QPushButton(widget);
        pushButton_ok->setObjectName(QString::fromUtf8("pushButton_ok"));

        verticalLayout->addWidget(pushButton_ok);


        retranslateUi(changePasswd);

        QMetaObject::connectSlotsByName(changePasswd);
    } // setupUi

    void retranslateUi(QWidget *changePasswd)
    {
        changePasswd->setWindowTitle(QCoreApplication::translate("changePasswd", "Form", nullptr));
        label->setText(QCoreApplication::translate("changePasswd", "\350\264\246\345\217\267", nullptr));
        label_2->setText(QCoreApplication::translate("changePasswd", "\345\216\237\345\257\206\347\240\201", nullptr));
        label_3->setText(QCoreApplication::translate("changePasswd", "\346\226\260\345\257\206\347\240\201", nullptr));
        pushButton_ok->setText(QCoreApplication::translate("changePasswd", "\347\241\256\345\256\232", nullptr));
    } // retranslateUi

};

namespace Ui {
    class changePasswd: public Ui_changePasswd {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHANGEPASSWD_H
