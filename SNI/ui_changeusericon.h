/********************************************************************************
** Form generated from reading UI file 'changeusericon.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHANGEUSERICON_H
#define UI_CHANGEUSERICON_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ChangeUserIcon
{
public:

    void setupUi(QWidget *ChangeUserIcon)
    {
        if (ChangeUserIcon->objectName().isEmpty())
            ChangeUserIcon->setObjectName(QString::fromUtf8("ChangeUserIcon"));
        ChangeUserIcon->resize(400, 300);

        retranslateUi(ChangeUserIcon);

        QMetaObject::connectSlotsByName(ChangeUserIcon);
    } // setupUi

    void retranslateUi(QWidget *ChangeUserIcon)
    {
        ChangeUserIcon->setWindowTitle(QCoreApplication::translate("ChangeUserIcon", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ChangeUserIcon: public Ui_ChangeUserIcon {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHANGEUSERICON_H
