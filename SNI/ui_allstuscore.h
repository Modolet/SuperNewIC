/********************************************************************************
** Form generated from reading UI file 'allstuscore.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ALLSTUSCORE_H
#define UI_ALLSTUSCORE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AllStuScore
{
public:
    QTableView *tableView;

    void setupUi(QWidget *AllStuScore)
    {
        if (AllStuScore->objectName().isEmpty())
            AllStuScore->setObjectName(QString::fromUtf8("AllStuScore"));
        AllStuScore->resize(315, 900);
        tableView = new QTableView(AllStuScore);
        tableView->setObjectName(QString::fromUtf8("tableView"));
        tableView->setGeometry(QRect(0, 0, 315, 900));

        retranslateUi(AllStuScore);

        QMetaObject::connectSlotsByName(AllStuScore);
    } // setupUi

    void retranslateUi(QWidget *AllStuScore)
    {
        AllStuScore->setWindowTitle(QCoreApplication::translate("AllStuScore", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AllStuScore: public Ui_AllStuScore {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ALLSTUSCORE_H
