/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.13.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *action_about;
    QAction *style1;
    QAction *style2;
    QAction *style3;
    QAction *style4;
    QAction *style5;
    QAction *style6;
    QWidget *centralwidget;
    QStackedWidget *stackedWidget;
    QWidget *page_list;
    QTableWidget *tableWidget_list;
    QWidget *page_notice;
    QTableWidget *tableWidget_notice;
    QWidget *page_status;
    QWidget *page_message;
    QListWidget *listWidget_2;
    QStackedWidget *stackedWidget_2;
    QWidget *page;
    QTextEdit *textEdit;
    QPushButton *pushButton;
    QWidget *page_2;
    QWidget *page_score;
    QTableWidget *tableWidget_score;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QPushButton *pushButton_list;
    QPushButton *pushButton_notice;
    QPushButton *pushButton_status;
    QPushButton *pushButton_message;
    QPushButton *pushButton_score;
    QMenuBar *menubar;
    QMenu *menu_file;
    QMenu *menu_style;
    QMenu *menu_help;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(808, 603);
        action_about = new QAction(MainWindow);
        action_about->setObjectName(QString::fromUtf8("action_about"));
        style1 = new QAction(MainWindow);
        style1->setObjectName(QString::fromUtf8("style1"));
        style2 = new QAction(MainWindow);
        style2->setObjectName(QString::fromUtf8("style2"));
        style3 = new QAction(MainWindow);
        style3->setObjectName(QString::fromUtf8("style3"));
        style4 = new QAction(MainWindow);
        style4->setObjectName(QString::fromUtf8("style4"));
        style5 = new QAction(MainWindow);
        style5->setObjectName(QString::fromUtf8("style5"));
        style6 = new QAction(MainWindow);
        style6->setObjectName(QString::fromUtf8("style6"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        stackedWidget = new QStackedWidget(centralwidget);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        stackedWidget->setGeometry(QRect(100, 0, 711, 581));
        page_list = new QWidget();
        page_list->setObjectName(QString::fromUtf8("page_list"));
        tableWidget_list = new QTableWidget(page_list);
        if (tableWidget_list->columnCount() < 4)
            tableWidget_list->setColumnCount(4);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget_list->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget_list->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget_list->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidget_list->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        tableWidget_list->setObjectName(QString::fromUtf8("tableWidget_list"));
        tableWidget_list->setGeometry(QRect(0, 0, 711, 581));
        stackedWidget->addWidget(page_list);
        page_notice = new QWidget();
        page_notice->setObjectName(QString::fromUtf8("page_notice"));
        tableWidget_notice = new QTableWidget(page_notice);
        if (tableWidget_notice->columnCount() < 4)
            tableWidget_notice->setColumnCount(4);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableWidget_notice->setHorizontalHeaderItem(0, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tableWidget_notice->setHorizontalHeaderItem(1, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        tableWidget_notice->setHorizontalHeaderItem(2, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        tableWidget_notice->setHorizontalHeaderItem(3, __qtablewidgetitem7);
        tableWidget_notice->setObjectName(QString::fromUtf8("tableWidget_notice"));
        tableWidget_notice->setGeometry(QRect(0, 0, 711, 581));
        stackedWidget->addWidget(page_notice);
        page_status = new QWidget();
        page_status->setObjectName(QString::fromUtf8("page_status"));
        stackedWidget->addWidget(page_status);
        page_message = new QWidget();
        page_message->setObjectName(QString::fromUtf8("page_message"));
        listWidget_2 = new QListWidget(page_message);
        new QListWidgetItem(listWidget_2);
        new QListWidgetItem(listWidget_2);
        new QListWidgetItem(listWidget_2);
        listWidget_2->setObjectName(QString::fromUtf8("listWidget_2"));
        listWidget_2->setGeometry(QRect(-5, 1, 151, 581));
        stackedWidget_2 = new QStackedWidget(page_message);
        stackedWidget_2->setObjectName(QString::fromUtf8("stackedWidget_2"));
        stackedWidget_2->setGeometry(QRect(149, -1, 561, 581));
        page = new QWidget();
        page->setObjectName(QString::fromUtf8("page"));
        textEdit = new QTextEdit(page);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setGeometry(QRect(0, 480, 461, 101));
        pushButton = new QPushButton(page);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(470, 500, 75, 61));
        stackedWidget_2->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName(QString::fromUtf8("page_2"));
        stackedWidget_2->addWidget(page_2);
        stackedWidget->addWidget(page_message);
        page_score = new QWidget();
        page_score->setObjectName(QString::fromUtf8("page_score"));
        tableWidget_score = new QTableWidget(page_score);
        if (tableWidget_score->columnCount() < 3)
            tableWidget_score->setColumnCount(3);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        tableWidget_score->setHorizontalHeaderItem(0, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        tableWidget_score->setHorizontalHeaderItem(1, __qtablewidgetitem9);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        tableWidget_score->setHorizontalHeaderItem(2, __qtablewidgetitem10);
        tableWidget_score->setObjectName(QString::fromUtf8("tableWidget_score"));
        tableWidget_score->setGeometry(QRect(0, 0, 711, 581));
        stackedWidget->addWidget(page_score);
        layoutWidget = new QWidget(centralwidget);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(0, 0, 101, 581));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        pushButton_list = new QPushButton(layoutWidget);
        pushButton_list->setObjectName(QString::fromUtf8("pushButton_list"));

        verticalLayout->addWidget(pushButton_list);

        pushButton_notice = new QPushButton(layoutWidget);
        pushButton_notice->setObjectName(QString::fromUtf8("pushButton_notice"));

        verticalLayout->addWidget(pushButton_notice);

        pushButton_status = new QPushButton(layoutWidget);
        pushButton_status->setObjectName(QString::fromUtf8("pushButton_status"));

        verticalLayout->addWidget(pushButton_status);

        pushButton_message = new QPushButton(layoutWidget);
        pushButton_message->setObjectName(QString::fromUtf8("pushButton_message"));

        verticalLayout->addWidget(pushButton_message);

        pushButton_score = new QPushButton(layoutWidget);
        pushButton_score->setObjectName(QString::fromUtf8("pushButton_score"));

        verticalLayout->addWidget(pushButton_score);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 808, 23));
        menu_file = new QMenu(menubar);
        menu_file->setObjectName(QString::fromUtf8("menu_file"));
        menu_style = new QMenu(menu_file);
        menu_style->setObjectName(QString::fromUtf8("menu_style"));
        menu_help = new QMenu(menubar);
        menu_help->setObjectName(QString::fromUtf8("menu_help"));
        MainWindow->setMenuBar(menubar);

        menubar->addAction(menu_file->menuAction());
        menubar->addAction(menu_help->menuAction());
        menu_file->addAction(menu_style->menuAction());
        menu_style->addAction(style1);
        menu_style->addAction(style2);
        menu_style->addAction(style3);
        menu_style->addAction(style4);
        menu_style->addAction(style5);
        menu_style->addAction(style6);
        menu_help->addAction(action_about);

        retranslateUi(MainWindow);

        stackedWidget->setCurrentIndex(4);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        action_about->setText(QCoreApplication::translate("MainWindow", "about", nullptr));
        style1->setText(QCoreApplication::translate("MainWindow", "1", nullptr));
        style2->setText(QCoreApplication::translate("MainWindow", "2", nullptr));
        style3->setText(QCoreApplication::translate("MainWindow", "3", nullptr));
        style4->setText(QCoreApplication::translate("MainWindow", "4", nullptr));
        style5->setText(QCoreApplication::translate("MainWindow", "5", nullptr));
        style6->setText(QCoreApplication::translate("MainWindow", "6", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableWidget_list->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("MainWindow", "\345\247\223\345\220\215", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget_list->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("MainWindow", "\345\255\246\345\217\267", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget_list->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("MainWindow", "\347\217\255\347\272\247", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget_list->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("MainWindow", "\346\210\220\347\273\251", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget_notice->horizontalHeaderItem(0);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("MainWindow", "\345\272\217\345\217\267", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidget_notice->horizontalHeaderItem(1);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("MainWindow", "\346\227\245\346\234\237", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = tableWidget_notice->horizontalHeaderItem(2);
        ___qtablewidgetitem6->setText(QCoreApplication::translate("MainWindow", "\345\206\205\345\256\271", nullptr));
        QTableWidgetItem *___qtablewidgetitem7 = tableWidget_notice->horizontalHeaderItem(3);
        ___qtablewidgetitem7->setText(QCoreApplication::translate("MainWindow", "\347\212\266\346\200\201", nullptr));

        const bool __sortingEnabled = listWidget_2->isSortingEnabled();
        listWidget_2->setSortingEnabled(false);
        QListWidgetItem *___qlistwidgetitem = listWidget_2->item(0);
        ___qlistwidgetitem->setText(QCoreApplication::translate("MainWindow", "\345\274\240\344\270\211", nullptr));
        QListWidgetItem *___qlistwidgetitem1 = listWidget_2->item(1);
        ___qlistwidgetitem1->setText(QCoreApplication::translate("MainWindow", "\346\235\216\345\233\233", nullptr));
        QListWidgetItem *___qlistwidgetitem2 = listWidget_2->item(2);
        ___qlistwidgetitem2->setText(QCoreApplication::translate("MainWindow", "\347\216\213\344\272\224", nullptr));
        listWidget_2->setSortingEnabled(__sortingEnabled);

        pushButton->setText(QCoreApplication::translate("MainWindow", "\345\217\221\351\200\201", nullptr));
        QTableWidgetItem *___qtablewidgetitem8 = tableWidget_score->horizontalHeaderItem(0);
        ___qtablewidgetitem8->setText(QCoreApplication::translate("MainWindow", "\345\247\223\345\220\215", nullptr));
        QTableWidgetItem *___qtablewidgetitem9 = tableWidget_score->horizontalHeaderItem(1);
        ___qtablewidgetitem9->setText(QCoreApplication::translate("MainWindow", "\345\255\246\345\217\267", nullptr));
        QTableWidgetItem *___qtablewidgetitem10 = tableWidget_score->horizontalHeaderItem(2);
        ___qtablewidgetitem10->setText(QCoreApplication::translate("MainWindow", "\346\210\220\347\273\251", nullptr));
        pushButton_list->setText(QCoreApplication::translate("MainWindow", "\345\255\246\347\224\237\345\210\227\350\241\250", nullptr));
        pushButton_notice->setText(QCoreApplication::translate("MainWindow", "\351\200\232\347\237\245\345\205\254\345\221\212", nullptr));
        pushButton_status->setText(QCoreApplication::translate("MainWindow", "\345\255\246\347\224\237\347\212\266\346\200\201", nullptr));
        pushButton_message->setText(QCoreApplication::translate("MainWindow", "\345\217\221\351\200\201\344\277\241\346\201\257", nullptr));
        pushButton_score->setText(QCoreApplication::translate("MainWindow", "\346\210\220\347\273\251\347\256\241\347\220\206", nullptr));
        menu_file->setTitle(QCoreApplication::translate("MainWindow", "\346\226\207\344\273\266", nullptr));
        menu_style->setTitle(QCoreApplication::translate("MainWindow", "\345\210\207\346\215\242\344\270\273\351\242\230", nullptr));
        menu_help->setTitle(QCoreApplication::translate("MainWindow", "\345\270\256\345\212\251", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
