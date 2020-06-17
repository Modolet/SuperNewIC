/********************************************************************************
** Form generated from reading UI file 'first.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FIRST_H
#define UI_FIRST_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_First
{
public:
    QWidget *widget;
    QGridLayout *gridLayout;
    QLabel *label;
    QLineEdit *lineEdit_ID;
    QLabel *label_2;
    QLineEdit *lineEdit_email;
    QLabel *label_3;
    QLineEdit *lineEdit_Vcode;
    QPushButton *pushButton_getVcode;
    QLabel *label_4;
    QLineEdit *lineEdit_pwd;
    QPushButton *pushButton_OK;

    void setupUi(QWidget *First)
    {
        if (First->objectName().isEmpty())
            First->setObjectName(QString::fromUtf8("First"));
        First->resize(318, 161);
        widget = new QWidget(First);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(20, 10, 276, 132));
        gridLayout = new QGridLayout(widget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(widget);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        lineEdit_ID = new QLineEdit(widget);
        lineEdit_ID->setObjectName(QString::fromUtf8("lineEdit_ID"));

        gridLayout->addWidget(lineEdit_ID, 0, 1, 1, 1);

        label_2 = new QLabel(widget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        lineEdit_email = new QLineEdit(widget);
        lineEdit_email->setObjectName(QString::fromUtf8("lineEdit_email"));

        gridLayout->addWidget(lineEdit_email, 1, 1, 1, 1);

        label_3 = new QLabel(widget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 2, 0, 1, 1);

        lineEdit_Vcode = new QLineEdit(widget);
        lineEdit_Vcode->setObjectName(QString::fromUtf8("lineEdit_Vcode"));

        gridLayout->addWidget(lineEdit_Vcode, 2, 1, 1, 1);

        pushButton_getVcode = new QPushButton(widget);
        pushButton_getVcode->setObjectName(QString::fromUtf8("pushButton_getVcode"));

        gridLayout->addWidget(pushButton_getVcode, 2, 2, 1, 1);

        label_4 = new QLabel(widget);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout->addWidget(label_4, 3, 0, 1, 1);

        lineEdit_pwd = new QLineEdit(widget);
        lineEdit_pwd->setObjectName(QString::fromUtf8("lineEdit_pwd"));

        gridLayout->addWidget(lineEdit_pwd, 3, 1, 1, 1);

        pushButton_OK = new QPushButton(widget);
        pushButton_OK->setObjectName(QString::fromUtf8("pushButton_OK"));

        gridLayout->addWidget(pushButton_OK, 4, 1, 1, 1);


        retranslateUi(First);

        QMetaObject::connectSlotsByName(First);
    } // setupUi

    void retranslateUi(QWidget *First)
    {
        First->setWindowTitle(QCoreApplication::translate("First", "Form", nullptr));
        label->setText(QCoreApplication::translate("First", "ID:", nullptr));
        label_2->setText(QCoreApplication::translate("First", "\351\202\256\347\256\261\357\274\232", nullptr));
        label_3->setText(QCoreApplication::translate("First", "\351\252\214\350\257\201\347\240\201\357\274\232", nullptr));
        pushButton_getVcode->setText(QCoreApplication::translate("First", "\347\202\271\345\207\273\350\216\267\345\217\226", nullptr));
        label_4->setText(QCoreApplication::translate("First", "\346\226\260\345\257\206\347\240\201\357\274\232", nullptr));
        pushButton_OK->setText(QCoreApplication::translate("First", "\347\241\256\345\256\232", nullptr));
    } // retranslateUi

};

namespace Ui {
    class First: public Ui_First {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FIRST_H
