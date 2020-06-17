/********************************************************************************
** Form generated from reading UI file 'studentexperimentalresult.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STUDENTEXPERIMENTALRESULT_H
#define UI_STUDENTEXPERIMENTALRESULT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_StudentExperimentalResult
{
public:
    QTableView *tableView;

    void setupUi(QWidget *StudentExperimentalResult)
    {
        if (StudentExperimentalResult->objectName().isEmpty())
            StudentExperimentalResult->setObjectName(QString::fromUtf8("StudentExperimentalResult"));
        StudentExperimentalResult->resize(150, 150);
        tableView = new QTableView(StudentExperimentalResult);
        tableView->setObjectName(QString::fromUtf8("tableView"));
        tableView->setGeometry(QRect(0, 0, 150, 150));

        retranslateUi(StudentExperimentalResult);

        QMetaObject::connectSlotsByName(StudentExperimentalResult);
    } // setupUi

    void retranslateUi(QWidget *StudentExperimentalResult)
    {
        StudentExperimentalResult->setWindowTitle(QCoreApplication::translate("StudentExperimentalResult", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class StudentExperimentalResult: public Ui_StudentExperimentalResult {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STUDENTEXPERIMENTALRESULT_H
