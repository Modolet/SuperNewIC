#ifndef STU_ACCESSPORT_H
#define STU_ACCESSPORT_H

#include <QWidget>
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QtMath>
#include <QTimer>
#include <QMessageBox>
#include <QDebug>


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

public:
    bool isMainWindowUse = true;    // 用作是否主窗口用的标识
    bool isSingletest = true;       // 用作是否单次测量的标识
    bool isStop = false;

private:
    Ui::Stu_AccessPort *ui;
    QSerialPort serial;             // 全局串口对象
    QByteArray data[16] = {"0", "1", "2", "3", "4", "5", "6", "7", "8", "9", "A", "B", "C", "D", "E", "F"};
    QByteArray vis;
    int index[6] = {0};
    int time = 0;
    double R0 = 0, R01 = 0, Rx = 0;
    QTimer *timer;                  // 创建一个全局定时器，硬件接收端口数据需要延迟一段时间

private:
    void findSerial();                          // 查找计算机可用串口
    void initSerials();                         // 初始化串口，全部默认
    void signalsToSlots();                      // 把信号和槽函数连接起来
    int getR0(int, int, int, int, int, int);    // 把控制R0的20位二进制代码转为十进制
    void circuitReset();                        // 参数归零
};

#endif // STU_ACCESSPORT_H
