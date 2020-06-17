/********************************************************************************
** Form generated from reading UI file 'stu_mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STU_MAINWINDOW_H
#define UI_STU_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Stu_MainWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout_5;
    QWidget *widget_2;
    QVBoxLayout *verticalLayout;
    QPushButton *pushButton_user;
    QFrame *line_3;
    QVBoxLayout *verticalLayout_2;
    QPushButton *pushButton_notice;
    QPushButton *pushButton_resTest;
    QPushButton *pushButton_resValueRecorde;
    QSpacerItem *verticalSpacer_8;
    QPushButton *pushButton_testSpecific;
    QSpacerItem *verticalSpacer_9;
    QFrame *line_2;
    QStackedWidget *stackedWidget;
    QWidget *page_studentInformation;
    QWidget *widget_3;
    QGridLayout *gridLayout_6;
    QPushButton *pushButton_sureChangePassword;
    QLineEdit *lineEdit_userClass;
    QLineEdit *lineEdit_changePasswords;
    QLabel *label_userPasswords;
    QLabel *label_userName;
    QLineEdit *lineEdit_passwords;
    QLabel *label_userClass;
    QLineEdit *lineEdit_userName;
    QLabel *label_ChangePasswords;
    QLineEdit *lineEdit_userId;
    QLabel *label_userId;
    QPushButton *pushButton_2;
    QWidget *page_notice;
    QGridLayout *gridLayout_8;
    QLabel *label;
    QSpacerItem *horizontalSpacer_8;
    QTextEdit *textEdit_notice1;
    QSpacerItem *verticalSpacer_3;
    QWidget *page_resTest;
    QGridLayout *gridLayout_7;
    QWidget *widget;
    QGridLayout *gridLayout_4;
    QSpacerItem *horizontalSpacer;
    QRadioButton *radioButton_singleTest;
    QSpacerItem *horizontalSpacer_5;
    QRadioButton *radioButton_repeatTest;
    QSpacerItem *horizontalSpacer_3;
    QSpacerItem *verticalSpacer;
    QSpacerItem *verticalSpacer_2;
    QGridLayout *gridLayout;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *pushButton_startTest;
    QSpacerItem *horizontalSpacer_6;
    QPushButton *pushButton_stopTest;
    QSpacerItem *horizontalSpacer_7;
    QPushButton *pushButton;
    QSpacerItem *horizontalSpacer_4;
    QTableView *tableView_page_resTest;
    QWidget *page_dataAnalyse;
    QGridLayout *gridLayout_3;
    QWidget *widget_4;
    QGridLayout *gridLayout_2;
    QLabel *label_averageValue;
    QLineEdit *lineEdit_averageValue;
    QLabel *label_variance;
    QLineEdit *lineEdit_variance;
    QLabel *label_standardDeviation;
    QLineEdit *lineEdit_standardDeviation;
    QPushButton *pushButton_deleteData;
    QPushButton *pushButton_clearAll;
    QSpacerItem *verticalSpacer_6;
    QTableView *tableView_page_dataAnalyse;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Stu_MainWindow)
    {
        if (Stu_MainWindow->objectName().isEmpty())
            Stu_MainWindow->setObjectName(QString::fromUtf8("Stu_MainWindow"));
        Stu_MainWindow->resize(656, 480);
        centralwidget = new QWidget(Stu_MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout_5 = new QGridLayout(centralwidget);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        widget_2 = new QWidget(centralwidget);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(widget_2->sizePolicy().hasHeightForWidth());
        widget_2->setSizePolicy(sizePolicy);
        verticalLayout = new QVBoxLayout(widget_2);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        pushButton_user = new QPushButton(widget_2);
        pushButton_user->setObjectName(QString::fromUtf8("pushButton_user"));

        verticalLayout->addWidget(pushButton_user);

        line_3 = new QFrame(widget_2);
        line_3->setObjectName(QString::fromUtf8("line_3"));
        line_3->setFrameShape(QFrame::HLine);
        line_3->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line_3);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        pushButton_notice = new QPushButton(widget_2);
        pushButton_notice->setObjectName(QString::fromUtf8("pushButton_notice"));

        verticalLayout_2->addWidget(pushButton_notice);

        pushButton_resTest = new QPushButton(widget_2);
        pushButton_resTest->setObjectName(QString::fromUtf8("pushButton_resTest"));

        verticalLayout_2->addWidget(pushButton_resTest);

        pushButton_resValueRecorde = new QPushButton(widget_2);
        pushButton_resValueRecorde->setObjectName(QString::fromUtf8("pushButton_resValueRecorde"));

        verticalLayout_2->addWidget(pushButton_resValueRecorde);


        verticalLayout->addLayout(verticalLayout_2);

        verticalSpacer_8 = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout->addItem(verticalSpacer_8);

        pushButton_testSpecific = new QPushButton(widget_2);
        pushButton_testSpecific->setObjectName(QString::fromUtf8("pushButton_testSpecific"));

        verticalLayout->addWidget(pushButton_testSpecific);

        verticalSpacer_9 = new QSpacerItem(20, 162, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_9);


        gridLayout_5->addWidget(widget_2, 0, 0, 1, 1);

        line_2 = new QFrame(centralwidget);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setFrameShape(QFrame::VLine);
        line_2->setFrameShadow(QFrame::Sunken);

        gridLayout_5->addWidget(line_2, 0, 1, 1, 1);

        stackedWidget = new QStackedWidget(centralwidget);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        stackedWidget->setEnabled(true);
        stackedWidget->setMinimumSize(QSize(100, 0));
        page_studentInformation = new QWidget();
        page_studentInformation->setObjectName(QString::fromUtf8("page_studentInformation"));
        widget_3 = new QWidget(page_studentInformation);
        widget_3->setObjectName(QString::fromUtf8("widget_3"));
        widget_3->setGeometry(QRect(10, 10, 286, 241));
        sizePolicy.setHeightForWidth(widget_3->sizePolicy().hasHeightForWidth());
        widget_3->setSizePolicy(sizePolicy);
        gridLayout_6 = new QGridLayout(widget_3);
        gridLayout_6->setObjectName(QString::fromUtf8("gridLayout_6"));
        pushButton_sureChangePassword = new QPushButton(widget_3);
        pushButton_sureChangePassword->setObjectName(QString::fromUtf8("pushButton_sureChangePassword"));

        gridLayout_6->addWidget(pushButton_sureChangePassword, 4, 2, 1, 1);

        lineEdit_userClass = new QLineEdit(widget_3);
        lineEdit_userClass->setObjectName(QString::fromUtf8("lineEdit_userClass"));

        gridLayout_6->addWidget(lineEdit_userClass, 2, 1, 1, 1);

        lineEdit_changePasswords = new QLineEdit(widget_3);
        lineEdit_changePasswords->setObjectName(QString::fromUtf8("lineEdit_changePasswords"));

        gridLayout_6->addWidget(lineEdit_changePasswords, 4, 1, 1, 1);

        label_userPasswords = new QLabel(widget_3);
        label_userPasswords->setObjectName(QString::fromUtf8("label_userPasswords"));
        sizePolicy.setHeightForWidth(label_userPasswords->sizePolicy().hasHeightForWidth());
        label_userPasswords->setSizePolicy(sizePolicy);
        label_userPasswords->setScaledContents(true);

        gridLayout_6->addWidget(label_userPasswords, 3, 0, 1, 1);

        label_userName = new QLabel(widget_3);
        label_userName->setObjectName(QString::fromUtf8("label_userName"));
        sizePolicy.setHeightForWidth(label_userName->sizePolicy().hasHeightForWidth());
        label_userName->setSizePolicy(sizePolicy);
        label_userName->setScaledContents(true);

        gridLayout_6->addWidget(label_userName, 0, 0, 1, 1);

        lineEdit_passwords = new QLineEdit(widget_3);
        lineEdit_passwords->setObjectName(QString::fromUtf8("lineEdit_passwords"));

        gridLayout_6->addWidget(lineEdit_passwords, 3, 1, 1, 1);

        label_userClass = new QLabel(widget_3);
        label_userClass->setObjectName(QString::fromUtf8("label_userClass"));
        sizePolicy.setHeightForWidth(label_userClass->sizePolicy().hasHeightForWidth());
        label_userClass->setSizePolicy(sizePolicy);
        label_userClass->setScaledContents(true);

        gridLayout_6->addWidget(label_userClass, 2, 0, 1, 1);

        lineEdit_userName = new QLineEdit(widget_3);
        lineEdit_userName->setObjectName(QString::fromUtf8("lineEdit_userName"));

        gridLayout_6->addWidget(lineEdit_userName, 1, 1, 1, 1);

        label_ChangePasswords = new QLabel(widget_3);
        label_ChangePasswords->setObjectName(QString::fromUtf8("label_ChangePasswords"));
        sizePolicy.setHeightForWidth(label_ChangePasswords->sizePolicy().hasHeightForWidth());
        label_ChangePasswords->setSizePolicy(sizePolicy);
        label_ChangePasswords->setScaledContents(true);

        gridLayout_6->addWidget(label_ChangePasswords, 4, 0, 1, 1);

        lineEdit_userId = new QLineEdit(widget_3);
        lineEdit_userId->setObjectName(QString::fromUtf8("lineEdit_userId"));

        gridLayout_6->addWidget(lineEdit_userId, 0, 1, 1, 1);

        label_userId = new QLabel(widget_3);
        label_userId->setObjectName(QString::fromUtf8("label_userId"));
        sizePolicy.setHeightForWidth(label_userId->sizePolicy().hasHeightForWidth());
        label_userId->setSizePolicy(sizePolicy);
        label_userId->setScaledContents(true);

        gridLayout_6->addWidget(label_userId, 1, 0, 1, 1);

        pushButton_2 = new QPushButton(widget_3);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));

        gridLayout_6->addWidget(pushButton_2, 5, 1, 1, 1);

        stackedWidget->addWidget(page_studentInformation);
        page_notice = new QWidget();
        page_notice->setObjectName(QString::fromUtf8("page_notice"));
        gridLayout_8 = new QGridLayout(page_notice);
        gridLayout_8->setObjectName(QString::fromUtf8("gridLayout_8"));
        label = new QLabel(page_notice);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout_8->addWidget(label, 0, 0, 1, 1);

        horizontalSpacer_8 = new QSpacerItem(419, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_8->addItem(horizontalSpacer_8, 0, 1, 1, 1);

        textEdit_notice1 = new QTextEdit(page_notice);
        textEdit_notice1->setObjectName(QString::fromUtf8("textEdit_notice1"));
        textEdit_notice1->setReadOnly(true);

        gridLayout_8->addWidget(textEdit_notice1, 1, 0, 1, 3);

        verticalSpacer_3 = new QSpacerItem(20, 197, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_8->addItem(verticalSpacer_3, 2, 2, 1, 1);

        stackedWidget->addWidget(page_notice);
        page_resTest = new QWidget();
        page_resTest->setObjectName(QString::fromUtf8("page_resTest"));
        gridLayout_7 = new QGridLayout(page_resTest);
        gridLayout_7->setObjectName(QString::fromUtf8("gridLayout_7"));
        widget = new QWidget(page_resTest);
        widget->setObjectName(QString::fromUtf8("widget"));
        gridLayout_4 = new QGridLayout(widget);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        horizontalSpacer = new QSpacerItem(101, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_4->addItem(horizontalSpacer, 0, 0, 1, 1);

        radioButton_singleTest = new QRadioButton(widget);
        radioButton_singleTest->setObjectName(QString::fromUtf8("radioButton_singleTest"));
        radioButton_singleTest->setChecked(true);

        gridLayout_4->addWidget(radioButton_singleTest, 0, 1, 1, 1);

        horizontalSpacer_5 = new QSpacerItem(38, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_4->addItem(horizontalSpacer_5, 0, 2, 1, 1);

        radioButton_repeatTest = new QRadioButton(widget);
        radioButton_repeatTest->setObjectName(QString::fromUtf8("radioButton_repeatTest"));

        gridLayout_4->addWidget(radioButton_repeatTest, 0, 3, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(101, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_4->addItem(horizontalSpacer_3, 0, 4, 1, 1);

        verticalSpacer = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Fixed);

        gridLayout_4->addItem(verticalSpacer, 1, 1, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Fixed);

        gridLayout_4->addItem(verticalSpacer_2, 1, 3, 1, 1);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        horizontalSpacer_2 = new QSpacerItem(101, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 0, 0, 1, 1);

        pushButton_startTest = new QPushButton(widget);
        pushButton_startTest->setObjectName(QString::fromUtf8("pushButton_startTest"));

        gridLayout->addWidget(pushButton_startTest, 0, 1, 1, 1);

        horizontalSpacer_6 = new QSpacerItem(38, 17, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_6, 0, 2, 1, 1);

        pushButton_stopTest = new QPushButton(widget);
        pushButton_stopTest->setObjectName(QString::fromUtf8("pushButton_stopTest"));

        gridLayout->addWidget(pushButton_stopTest, 0, 3, 1, 1);

        horizontalSpacer_7 = new QSpacerItem(38, 17, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_7, 0, 4, 1, 1);

        pushButton = new QPushButton(widget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        gridLayout->addWidget(pushButton, 0, 5, 1, 1);

        horizontalSpacer_4 = new QSpacerItem(101, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_4, 0, 6, 1, 1);


        gridLayout_4->addLayout(gridLayout, 2, 0, 1, 5);


        gridLayout_7->addWidget(widget, 0, 0, 1, 1);

        tableView_page_resTest = new QTableView(page_resTest);
        tableView_page_resTest->setObjectName(QString::fromUtf8("tableView_page_resTest"));

        gridLayout_7->addWidget(tableView_page_resTest, 1, 0, 1, 1);

        stackedWidget->addWidget(page_resTest);
        page_dataAnalyse = new QWidget();
        page_dataAnalyse->setObjectName(QString::fromUtf8("page_dataAnalyse"));
        gridLayout_3 = new QGridLayout(page_dataAnalyse);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        widget_4 = new QWidget(page_dataAnalyse);
        widget_4->setObjectName(QString::fromUtf8("widget_4"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(widget_4->sizePolicy().hasHeightForWidth());
        widget_4->setSizePolicy(sizePolicy1);
        gridLayout_2 = new QGridLayout(widget_4);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        label_averageValue = new QLabel(widget_4);
        label_averageValue->setObjectName(QString::fromUtf8("label_averageValue"));

        gridLayout_2->addWidget(label_averageValue, 0, 0, 1, 1);

        lineEdit_averageValue = new QLineEdit(widget_4);
        lineEdit_averageValue->setObjectName(QString::fromUtf8("lineEdit_averageValue"));
        lineEdit_averageValue->setReadOnly(true);

        gridLayout_2->addWidget(lineEdit_averageValue, 1, 0, 1, 1);

        label_variance = new QLabel(widget_4);
        label_variance->setObjectName(QString::fromUtf8("label_variance"));

        gridLayout_2->addWidget(label_variance, 2, 0, 1, 1);

        lineEdit_variance = new QLineEdit(widget_4);
        lineEdit_variance->setObjectName(QString::fromUtf8("lineEdit_variance"));
        lineEdit_variance->setReadOnly(true);

        gridLayout_2->addWidget(lineEdit_variance, 3, 0, 1, 1);

        label_standardDeviation = new QLabel(widget_4);
        label_standardDeviation->setObjectName(QString::fromUtf8("label_standardDeviation"));

        gridLayout_2->addWidget(label_standardDeviation, 4, 0, 1, 1);

        lineEdit_standardDeviation = new QLineEdit(widget_4);
        lineEdit_standardDeviation->setObjectName(QString::fromUtf8("lineEdit_standardDeviation"));
        lineEdit_standardDeviation->setReadOnly(true);

        gridLayout_2->addWidget(lineEdit_standardDeviation, 5, 0, 1, 1);

        pushButton_deleteData = new QPushButton(widget_4);
        pushButton_deleteData->setObjectName(QString::fromUtf8("pushButton_deleteData"));

        gridLayout_2->addWidget(pushButton_deleteData, 6, 0, 1, 1);

        pushButton_clearAll = new QPushButton(widget_4);
        pushButton_clearAll->setObjectName(QString::fromUtf8("pushButton_clearAll"));

        gridLayout_2->addWidget(pushButton_clearAll, 7, 0, 1, 1);


        gridLayout_3->addWidget(widget_4, 0, 1, 1, 1);

        verticalSpacer_6 = new QSpacerItem(20, 283, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_3->addItem(verticalSpacer_6, 1, 1, 1, 1);

        tableView_page_dataAnalyse = new QTableView(page_dataAnalyse);
        tableView_page_dataAnalyse->setObjectName(QString::fromUtf8("tableView_page_dataAnalyse"));

        gridLayout_3->addWidget(tableView_page_dataAnalyse, 0, 0, 2, 1);

        stackedWidget->addWidget(page_dataAnalyse);

        gridLayout_5->addWidget(stackedWidget, 0, 2, 1, 1);

        Stu_MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Stu_MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 656, 23));
        Stu_MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(Stu_MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        Stu_MainWindow->setStatusBar(statusbar);

        retranslateUi(Stu_MainWindow);

        stackedWidget->setCurrentIndex(2);


        QMetaObject::connectSlotsByName(Stu_MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *Stu_MainWindow)
    {
        Stu_MainWindow->setWindowTitle(QCoreApplication::translate("Stu_MainWindow", "Stu_MainWindow", nullptr));
        pushButton_user->setText(QCoreApplication::translate("Stu_MainWindow", "\344\270\252\344\272\272\344\277\241\346\201\257", nullptr));
        pushButton_notice->setText(QCoreApplication::translate("Stu_MainWindow", "\351\200\232\347\237\245\345\205\254\345\221\212", nullptr));
        pushButton_resTest->setText(QCoreApplication::translate("Stu_MainWindow", "\347\224\265\351\230\273\346\265\213\351\207\217", nullptr));
        pushButton_resValueRecorde->setText(QCoreApplication::translate("Stu_MainWindow", "\351\230\273\345\200\274\345\210\206\346\236\220", nullptr));
        pushButton_testSpecific->setText(QCoreApplication::translate("Stu_MainWindow", "\346\265\213\350\257\225\344\270\223\347\224\250", nullptr));
        pushButton_sureChangePassword->setText(QCoreApplication::translate("Stu_MainWindow", "\347\241\256\350\256\244\344\277\256\346\224\271", nullptr));
        label_userPasswords->setText(QCoreApplication::translate("Stu_MainWindow", "<html><head/><body><p>\345\257\206\347\240\201</p></body></html>", nullptr));
        label_userName->setText(QCoreApplication::translate("Stu_MainWindow", "<html><head/><body><p>\345\247\223\345\220\215</p></body></html>", nullptr));
        label_userClass->setText(QCoreApplication::translate("Stu_MainWindow", "<html><head/><body><p>\347\217\255\347\272\247</p></body></html>", nullptr));
        label_ChangePasswords->setText(QCoreApplication::translate("Stu_MainWindow", "<html><head/><body><p>\344\277\256\346\224\271\345\257\206\347\240\201</p></body></html>", nullptr));
        label_userId->setText(QCoreApplication::translate("Stu_MainWindow", "<html><head/><body><p>\345\255\246\345\217\267</p></body></html>", nullptr));
        pushButton_2->setText(QCoreApplication::translate("Stu_MainWindow", "\351\200\200\345\207\272\347\231\273\345\275\225", nullptr));
        label->setText(QCoreApplication::translate("Stu_MainWindow", "\351\200\232\347\237\245\345\205\254\345\221\212", nullptr));
        radioButton_singleTest->setText(QCoreApplication::translate("Stu_MainWindow", "\345\215\225\346\254\241\346\265\213\350\257\225", nullptr));
        radioButton_repeatTest->setText(QCoreApplication::translate("Stu_MainWindow", "\345\244\232\346\254\241\346\265\213\350\257\225", nullptr));
        pushButton_startTest->setText(QCoreApplication::translate("Stu_MainWindow", "\345\274\200\345\247\213\346\265\213\350\257\225", nullptr));
        pushButton_stopTest->setText(QCoreApplication::translate("Stu_MainWindow", "\345\201\234\346\255\242\346\265\213\350\257\225", nullptr));
        pushButton->setText(QCoreApplication::translate("Stu_MainWindow", "\345\244\215\344\275\215", nullptr));
        label_averageValue->setText(QCoreApplication::translate("Stu_MainWindow", "Rx\345\235\207\345\200\274", nullptr));
        label_variance->setText(QCoreApplication::translate("Stu_MainWindow", "Rx\346\226\271\345\267\256", nullptr));
        label_standardDeviation->setText(QCoreApplication::translate("Stu_MainWindow", "Rx\346\240\207\345\207\206\345\267\256", nullptr));
#if QT_CONFIG(tooltip)
        pushButton_deleteData->setToolTip(QCoreApplication::translate("Stu_MainWindow", "\345\277\205\351\241\273\351\200\211\344\270\255\344\270\200\346\225\264\350\241\214\346\211\215\345\217\257\344\273\245\345\210\240\351\231\244\344\270\200\350\241\214", nullptr));
#endif // QT_CONFIG(tooltip)
        pushButton_deleteData->setText(QCoreApplication::translate("Stu_MainWindow", "\345\210\240\351\231\244", nullptr));
        pushButton_clearAll->setText(QCoreApplication::translate("Stu_MainWindow", "\346\270\205\347\251\272", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Stu_MainWindow: public Ui_Stu_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STU_MAINWINDOW_H
