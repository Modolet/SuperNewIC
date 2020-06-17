/********************************************************************************
** Form generated from reading UI file 'stu_accessport.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STU_ACCESSPORT_H
#define UI_STU_ACCESSPORT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Stu_AccessPort
{
public:
    QGridLayout *gridLayout_3;
    QPlainTextEdit *plainTextEdit_receiveDisplay;
    QWidget *widget;
    QGridLayout *gridLayout;
    QLabel *label_baudRate;
    QPushButton *pushButton_clearReceive;
    QComboBox *comboBox_dataBits;
    QSpacerItem *verticalSpacer;
    QComboBox *comboBox_stopBits;
    QComboBox *comboBox_parity;
    QComboBox *comboBox_baudRate;
    QLabel *label_dataBits;
    QCheckBox *checkBox_openSerial;
    QLabel *label_stopBits;
    QLabel *label_baudRate_2;
    QComboBox *comboBox_serialSelect;
    QLabel *label_parity;
    QWidget *widget_2;
    QGridLayout *gridLayout_2;
    QPlainTextEdit *plainTextEdit_singleSend;
    QPushButton *pushButton_send;
    QPushButton *pushButton_clearSend;
    QLabel *label;

    void setupUi(QWidget *Stu_AccessPort)
    {
        if (Stu_AccessPort->objectName().isEmpty())
            Stu_AccessPort->setObjectName(QString::fromUtf8("Stu_AccessPort"));
        Stu_AccessPort->resize(599, 496);
        gridLayout_3 = new QGridLayout(Stu_AccessPort);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        plainTextEdit_receiveDisplay = new QPlainTextEdit(Stu_AccessPort);
        plainTextEdit_receiveDisplay->setObjectName(QString::fromUtf8("plainTextEdit_receiveDisplay"));
        plainTextEdit_receiveDisplay->setReadOnly(true);

        gridLayout_3->addWidget(plainTextEdit_receiveDisplay, 0, 0, 1, 1);

        widget = new QWidget(Stu_AccessPort);
        widget->setObjectName(QString::fromUtf8("widget"));
        gridLayout = new QGridLayout(widget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label_baudRate = new QLabel(widget);
        label_baudRate->setObjectName(QString::fromUtf8("label_baudRate"));

        gridLayout->addWidget(label_baudRate, 2, 0, 1, 1);

        pushButton_clearReceive = new QPushButton(widget);
        pushButton_clearReceive->setObjectName(QString::fromUtf8("pushButton_clearReceive"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(10);
        sizePolicy.setHeightForWidth(pushButton_clearReceive->sizePolicy().hasHeightForWidth());
        pushButton_clearReceive->setSizePolicy(sizePolicy);

        gridLayout->addWidget(pushButton_clearReceive, 8, 0, 1, 1);

        comboBox_dataBits = new QComboBox(widget);
        comboBox_dataBits->addItem(QString());
        comboBox_dataBits->addItem(QString());
        comboBox_dataBits->addItem(QString());
        comboBox_dataBits->addItem(QString());
        comboBox_dataBits->setObjectName(QString::fromUtf8("comboBox_dataBits"));

        gridLayout->addWidget(comboBox_dataBits, 4, 1, 1, 1);

        verticalSpacer = new QSpacerItem(20, 100, QSizePolicy::Minimum, QSizePolicy::Fixed);

        gridLayout->addItem(verticalSpacer, 7, 0, 1, 1);

        comboBox_stopBits = new QComboBox(widget);
        comboBox_stopBits->addItem(QString());
        comboBox_stopBits->addItem(QString());
        comboBox_stopBits->addItem(QString());
        comboBox_stopBits->setObjectName(QString::fromUtf8("comboBox_stopBits"));

        gridLayout->addWidget(comboBox_stopBits, 3, 1, 1, 1);

        comboBox_parity = new QComboBox(widget);
        comboBox_parity->addItem(QString());
        comboBox_parity->addItem(QString());
        comboBox_parity->addItem(QString());
        comboBox_parity->setObjectName(QString::fromUtf8("comboBox_parity"));

        gridLayout->addWidget(comboBox_parity, 5, 1, 1, 1);

        comboBox_baudRate = new QComboBox(widget);
        comboBox_baudRate->addItem(QString());
        comboBox_baudRate->addItem(QString());
        comboBox_baudRate->addItem(QString());
        comboBox_baudRate->addItem(QString());
        comboBox_baudRate->addItem(QString());
        comboBox_baudRate->addItem(QString());
        comboBox_baudRate->addItem(QString());
        comboBox_baudRate->addItem(QString());
        comboBox_baudRate->setObjectName(QString::fromUtf8("comboBox_baudRate"));

        gridLayout->addWidget(comboBox_baudRate, 2, 1, 1, 1);

        label_dataBits = new QLabel(widget);
        label_dataBits->setObjectName(QString::fromUtf8("label_dataBits"));

        gridLayout->addWidget(label_dataBits, 4, 0, 1, 1);

        checkBox_openSerial = new QCheckBox(widget);
        checkBox_openSerial->setObjectName(QString::fromUtf8("checkBox_openSerial"));
        checkBox_openSerial->setChecked(false);

        gridLayout->addWidget(checkBox_openSerial, 6, 0, 1, 1);

        label_stopBits = new QLabel(widget);
        label_stopBits->setObjectName(QString::fromUtf8("label_stopBits"));

        gridLayout->addWidget(label_stopBits, 3, 0, 1, 1);

        label_baudRate_2 = new QLabel(widget);
        label_baudRate_2->setObjectName(QString::fromUtf8("label_baudRate_2"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label_baudRate_2->sizePolicy().hasHeightForWidth());
        label_baudRate_2->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(label_baudRate_2, 0, 0, 1, 1);

        comboBox_serialSelect = new QComboBox(widget);
        comboBox_serialSelect->setObjectName(QString::fromUtf8("comboBox_serialSelect"));

        gridLayout->addWidget(comboBox_serialSelect, 1, 0, 1, 2);

        label_parity = new QLabel(widget);
        label_parity->setObjectName(QString::fromUtf8("label_parity"));

        gridLayout->addWidget(label_parity, 5, 0, 1, 1);


        gridLayout_3->addWidget(widget, 0, 1, 1, 1);

        widget_2 = new QWidget(Stu_AccessPort);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(1);
        sizePolicy2.setHeightForWidth(widget_2->sizePolicy().hasHeightForWidth());
        widget_2->setSizePolicy(sizePolicy2);
        gridLayout_2 = new QGridLayout(widget_2);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        plainTextEdit_singleSend = new QPlainTextEdit(widget_2);
        plainTextEdit_singleSend->setObjectName(QString::fromUtf8("plainTextEdit_singleSend"));

        gridLayout_2->addWidget(plainTextEdit_singleSend, 1, 0, 2, 1);

        pushButton_send = new QPushButton(widget_2);
        pushButton_send->setObjectName(QString::fromUtf8("pushButton_send"));
        sizePolicy1.setHeightForWidth(pushButton_send->sizePolicy().hasHeightForWidth());
        pushButton_send->setSizePolicy(sizePolicy1);

        gridLayout_2->addWidget(pushButton_send, 1, 1, 1, 1);

        pushButton_clearSend = new QPushButton(widget_2);
        pushButton_clearSend->setObjectName(QString::fromUtf8("pushButton_clearSend"));
        sizePolicy1.setHeightForWidth(pushButton_clearSend->sizePolicy().hasHeightForWidth());
        pushButton_clearSend->setSizePolicy(sizePolicy1);

        gridLayout_2->addWidget(pushButton_clearSend, 2, 1, 1, 1);

        label = new QLabel(widget_2);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout_2->addWidget(label, 0, 0, 1, 1);


        gridLayout_3->addWidget(widget_2, 1, 0, 1, 2);


        retranslateUi(Stu_AccessPort);

        comboBox_baudRate->setCurrentIndex(2);
        comboBox_serialSelect->setCurrentIndex(-1);


        QMetaObject::connectSlotsByName(Stu_AccessPort);
    } // setupUi

    void retranslateUi(QWidget *Stu_AccessPort)
    {
        Stu_AccessPort->setWindowTitle(QCoreApplication::translate("Stu_AccessPort", "Form", nullptr));
        label_baudRate->setText(QCoreApplication::translate("Stu_AccessPort", "\346\263\242\347\211\271\347\216\207", nullptr));
        pushButton_clearReceive->setText(QCoreApplication::translate("Stu_AccessPort", "\346\270\205\351\231\244\346\216\245\345\217\227", nullptr));
        comboBox_dataBits->setItemText(0, QCoreApplication::translate("Stu_AccessPort", "8", nullptr));
        comboBox_dataBits->setItemText(1, QCoreApplication::translate("Stu_AccessPort", "7", nullptr));
        comboBox_dataBits->setItemText(2, QCoreApplication::translate("Stu_AccessPort", "6", nullptr));
        comboBox_dataBits->setItemText(3, QCoreApplication::translate("Stu_AccessPort", "5", nullptr));

        comboBox_stopBits->setItemText(0, QCoreApplication::translate("Stu_AccessPort", "1", nullptr));
        comboBox_stopBits->setItemText(1, QCoreApplication::translate("Stu_AccessPort", "1.5", nullptr));
        comboBox_stopBits->setItemText(2, QCoreApplication::translate("Stu_AccessPort", "2", nullptr));

        comboBox_parity->setItemText(0, QCoreApplication::translate("Stu_AccessPort", "\346\227\240", nullptr));
        comboBox_parity->setItemText(1, QCoreApplication::translate("Stu_AccessPort", "\345\245\207\346\243\200\351\252\214", nullptr));
        comboBox_parity->setItemText(2, QCoreApplication::translate("Stu_AccessPort", "\345\201\266\346\240\241\351\252\214", nullptr));

        comboBox_baudRate->setItemText(0, QCoreApplication::translate("Stu_AccessPort", "1200", nullptr));
        comboBox_baudRate->setItemText(1, QCoreApplication::translate("Stu_AccessPort", "2400", nullptr));
        comboBox_baudRate->setItemText(2, QCoreApplication::translate("Stu_AccessPort", "4800", nullptr));
        comboBox_baudRate->setItemText(3, QCoreApplication::translate("Stu_AccessPort", "9600", nullptr));
        comboBox_baudRate->setItemText(4, QCoreApplication::translate("Stu_AccessPort", "19200", nullptr));
        comboBox_baudRate->setItemText(5, QCoreApplication::translate("Stu_AccessPort", "38400", nullptr));
        comboBox_baudRate->setItemText(6, QCoreApplication::translate("Stu_AccessPort", "57600", nullptr));
        comboBox_baudRate->setItemText(7, QCoreApplication::translate("Stu_AccessPort", "115200", nullptr));

        comboBox_baudRate->setCurrentText(QCoreApplication::translate("Stu_AccessPort", "4800", nullptr));
        label_dataBits->setText(QCoreApplication::translate("Stu_AccessPort", "\346\225\260\346\215\256\344\275\215", nullptr));
        checkBox_openSerial->setText(QCoreApplication::translate("Stu_AccessPort", "\346\211\223\345\274\200\344\270\262\345\217\243", nullptr));
        label_stopBits->setText(QCoreApplication::translate("Stu_AccessPort", "\345\201\234\346\255\242\344\275\215", nullptr));
        label_baudRate_2->setText(QCoreApplication::translate("Stu_AccessPort", "\344\270\262\345\217\243\351\200\211\346\213\251", nullptr));
        label_parity->setText(QCoreApplication::translate("Stu_AccessPort", "\345\245\207\345\201\266\346\240\241\351\252\214\344\275\215", nullptr));
        pushButton_send->setText(QCoreApplication::translate("Stu_AccessPort", "\345\217\221\351\200\201", nullptr));
        pushButton_clearSend->setText(QCoreApplication::translate("Stu_AccessPort", "\346\270\205\351\231\244\345\217\221\351\200\201", nullptr));
        label->setText(QCoreApplication::translate("Stu_AccessPort", "\346\225\260\346\215\256\345\217\221\351\200\201\357\274\232", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Stu_AccessPort: public Ui_Stu_AccessPort {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STU_ACCESSPORT_H
