#ifndef TEST_H
#define TEST_H

#include <QWidget>
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QDebug>

namespace Ui {
class Test;
}

class Test : public QWidget
{
    Q_OBJECT

public:
    explicit Test(QWidget *parent = nullptr);
    ~Test();

    void mainWinSend(QByteArray str);

signals:
    void testDone(double, double, double, double, double);          // 每一组测量完成的信号

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

public:
    bool isMainWindowUse = true;    // 用作是否主窗口用的标识
    bool isSingletest = true;       // 用作是否单次测量的标识

private:
    Ui::Test *ui;
    QSerialPort serial;             // 全局串口对象


private:
    void findSerial();              // 查找计算机可用串口
    void initSerials();             // 初始化串口，全部默认
    void signalsToSlots();          // 把信号和槽函数连接起来
};

#endif // TEST_H
