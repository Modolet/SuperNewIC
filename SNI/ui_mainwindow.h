/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>
#include <studentlist.h>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *pushButton_menu;
    QPushButton *pushButton_exit;
    StudentList *studentList;
    QToolButton *toolButton_icon;
    QLabel *label_name;
    QLabel *label_sign;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(235, 600);
        QSizePolicy sizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        layoutWidget = new QWidget(centralwidget);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(0, 570, 239, 25));
        horizontalLayout_3 = new QHBoxLayout(layoutWidget);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        pushButton_menu = new QPushButton(layoutWidget);
        pushButton_menu->setObjectName(QString::fromUtf8("pushButton_menu"));

        horizontalLayout_3->addWidget(pushButton_menu);

        pushButton_exit = new QPushButton(layoutWidget);
        pushButton_exit->setObjectName(QString::fromUtf8("pushButton_exit"));

        horizontalLayout_3->addWidget(pushButton_exit);

        studentList = new StudentList(centralwidget);
        studentList->setObjectName(QString::fromUtf8("studentList"));
        studentList->setGeometry(QRect(0, 64, 235, 501));
        toolButton_icon = new QToolButton(centralwidget);
        toolButton_icon->setObjectName(QString::fromUtf8("toolButton_icon"));
        toolButton_icon->setGeometry(QRect(5, 5, 50, 50));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(toolButton_icon->sizePolicy().hasHeightForWidth());
        toolButton_icon->setSizePolicy(sizePolicy1);
        toolButton_icon->setMinimumSize(QSize(50, 50));
        toolButton_icon->setMaximumSize(QSize(50, 50));
        toolButton_icon->setBaseSize(QSize(50, 50));
        label_name = new QLabel(centralwidget);
        label_name->setObjectName(QString::fromUtf8("label_name"));
        label_name->setGeometry(QRect(65, 10, 160, 16));
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        label_name->setFont(font);
        label_sign = new QLabel(centralwidget);
        label_sign->setObjectName(QString::fromUtf8("label_sign"));
        label_sign->setGeometry(QRect(65, 35, 160, 16));
        QFont font1;
        font1.setPointSize(9);
        font1.setBold(false);
        font1.setWeight(50);
        label_sign->setFont(font1);
        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        pushButton_menu->setText(QCoreApplication::translate("MainWindow", "\350\217\234\345\215\225", nullptr));
        pushButton_exit->setText(QCoreApplication::translate("MainWindow", "\351\200\200\345\207\272\347\231\273\345\275\225", nullptr));
        toolButton_icon->setText(QCoreApplication::translate("MainWindow", "...", nullptr));
        label_name->setText(QCoreApplication::translate("MainWindow", "\345\220\215\347\247\260", nullptr));
        label_sign->setText(QCoreApplication::translate("MainWindow", "\347\255\276\345\220\215", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
