#ifndef STU_ACCESSPORT_H
#define STU_ACCESSPORT_H

#if _MSC_VER >= 1600	// MSVC2015 > 1899,	MSVC_VER = 14.0
#pragma execution_character_set("utf-8")
#endif

#include <QWidget>
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QtMath>
#include <QMessageBox>
#include <QDebug>
#include <QTimer>
#include "stu_showtalkdata.h"


namespace Ui {
class Stu_AccessPort;
}

class Stu_AccessPort : public QWidget
{
    Q_OBJECT

public:
    explicit Stu_AccessPort(QWidget *parent = nullptr);
    ~Stu_AccessPort();

    void mainWinSend(QByteArray str);
    void circuitReset();                        // 参数归零

signals:
    void testDone(double, double, double);          // 每一组测量完成的信号

public slots:
    void slot_singleTest();                 // 单次测量槽函数
    void slot_repeatTest();                 // 多次测量槽函数

private slots:
    void on_comboBox_serialSelect_currentIndexChanged(int index);

    void on_comboBox_baudRate_currentIndexChanged(int index);

    void on_comboBox_stopBits_currentIndexChanged(int index);

    void on_comboBox_dataBits_currentIndexChanged(int index);

    void on_comboBox_parity_currentIndexChanged(int index);

    void on_checkBox_openSerial_stateChanged(int arg1);

    void on_comboBox_serialSelect_currentTextChanged(const QString &arg1);

    void on_pushButton_send_clicked();

    void on_pushButton_clearSend_clicked();

    void readData();

    void on_pushButton_clearReceive_clicked();

    void on_plainTextEdit_singleSend_textChanged();

    void on_checkBox_16Show_stateChanged(int arg1);

public:
    bool isMainWindowUse = true;    // 用作是否主窗口用的标识
    bool isSingletest = true;       // 用作是否单次测量的标识
    bool isStop = false;
    Stu_ShowTalkData *showDataWidge;

private:
    Ui::Stu_AccessPort *ui;
    QSerialPort serial;             // 全局串口对象
    //int index[3] = {0, 0, 0};
    QByteArray vis;
    int time = 0;
    double R0 = 0, R01 = 0, Rx = 0;
    QTimer *timer;                  // 创建一个全局定时器，硬件接收端口数据需要延迟一段时间
    QString str_16, str_char;

    int start1 = 0x00, start2 = 0x00, end1 = 0xFF, end2 = 0xFF, mid1, mid2;
    int startArr[12] = {0x00, 0x00, 0x00,
                        0x40, 0x00, 0x00,
                        0x00, 0x00, 0x00,
                        0x00, 0xFF, 0XFF};
    QByteArray recStart, recEnd;
    bool isDone = false;
    char conver = 0x00;
    QString showData;
    int cnt = 0;


private:
    void findSerial();                          // 查找计算机可用串口
    void initSerials();                         // 初始化串口，全部默认
    void signalsToSlots();                      // 把信号和槽函数连接起来
    void circuitPartReset();                    // 电路部分参数置零
    void converByte(bool, QString);
    QString QByteArrayToHEX(QByteArray buf);
};

#endif // STU_ACCESSPORT_H
