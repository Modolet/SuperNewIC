#include "test.h"
#include "ui_test.h"

Test::Test(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Test)
{
    ui->setupUi(this);

    findSerial();               // 获取有用或者闲置端口，并且添加到串口选择下拉框
    initSerials();              // 初始化串口，设置波特率，停止位...
    signalsToSlots();
    ui->checkBox_openSerial->setCheckState(Qt::Checked);    // 打开窗口选中
}

Test::~Test()
{
    delete ui;
}


void Test::signalsToSlots()             // 把信号和槽函数连接起来
{
    // 在测试专用下，一旦串口有数据进来就执行测试窗口的槽函数
    connect(&serial, &QSerialPort::readyRead, this, &Test::readData);
    // 主窗口进行单次测量的时候，调用单次测量槽函数
    connect(&serial, &QSerialPort::readyRead, this, &Test::slot_singleTest); 
    // 主窗口进行单次测量的时候，调用多次测量槽函数
    connect(&serial, &QSerialPort::readyRead, this, &Test::slot_repeatTest);
}

void Test::findSerial()                 // 查找计算机可用串口
{
    foreach(const QSerialPortInfo &info,QSerialPortInfo::availablePorts())
    {
        QSerialPort tempSerial;
        tempSerial.setPort(info);
        if(tempSerial.open(QIODevice::ReadWrite))
        {
            ui->comboBox_serialSelect->addItem(tempSerial.portName());
            tempSerial.close();
        }
    }
}

void Test::initSerials()                                                // 初始化窗口
{
    serial.setPortName(ui->comboBox_serialSelect->currentText());       // 设置串口名
    serial.setBaudRate(ui->comboBox_baudRate->currentText().toInt());   // 设置波特率
    serial.setStopBits(QSerialPort::OneStop);                           // 设置停止位
    serial.setDataBits(QSerialPort::Data8);                             // 设置数据位
    serial.setParity(QSerialPort::NoParity);                            // 设置校验位
    serial.setFlowControl(QSerialPort::NoFlowControl);                  // 设置流控制
}


// 如果串口当前选择端口名改变，串口端口名设置为改变后的值
void Test::on_comboBox_serialSelect_currentIndexChanged(int index)
{
    serial.setPortName(ui->comboBox_serialSelect->currentText());
}
// 如果串口当前选择波特率改变，串口波特率设置为改变后的值
void Test::on_comboBox_baudRate_currentIndexChanged(int index)
{
    serial.setBaudRate(ui->comboBox_baudRate->currentText().toInt());
}

// 如果串口当前选择停止位位改变，串口停止位设置为改变后的值
void Test::on_comboBox_stopBits_currentIndexChanged(int index)
{
    switch(index)
    {
        case 0:
            serial.setStopBits(QSerialPort::OneStop); break;
        case 1:
            serial.setStopBits(QSerialPort::OneAndHalfStop); break;
        case 2:
            serial.setStopBits(QSerialPort::TwoStop); break;
    }
}

// 如果串口当前选择数据位改变，串口数据位设置为改变后的值
void Test::on_comboBox_dataBits_currentIndexChanged(int index)
{
    switch(index)
    {
        case 0:
            serial.setDataBits(QSerialPort::Data8);  break;
        case 1:
            serial.setDataBits(QSerialPort::Data7);  break;
        case 2:
            serial.setDataBits(QSerialPort::Data6);  break;
        case 3:
            serial.setDataBits(QSerialPort::Data5);  break;
    }
}

// 如果串口当前选择校验位改变，串口校验位设置为改变后的值
void Test::on_comboBox_parity_currentIndexChanged(int index)
{
    switch(index)
    {
        case 0:
            serial.setParity(QSerialPort::NoParity);  break;
        case 1:
            serial.setParity(QSerialPort::EvenParity);  break;
        case 2:
            serial.setParity(QSerialPort::OddParity);  break;
    }
}

// 利用复选框控制串口的打开还是关闭
void Test::on_checkBox_openSerial_stateChanged(int arg1)
{
    switch(arg1)
    {
        case Qt::Unchecked:
            serial.close(); break;
        case Qt::Checked:
            serial.open(QIODevice::ReadWrite); break;
    }
}


// 切换端口
void Test::on_comboBox_serialSelect_currentTextChanged(const QString &arg1)
{
    serial.close();
    serial.setPortName(arg1);
    if(ui->checkBox_openSerial->checkState() == Qt::Checked)
        serial.open(QIODevice::ReadWrite);
}


// 发送
void Test::on_pushButton_send_clicked()
{
    serial.write(ui->plainTextEdit_singleSend->toPlainText().toLatin1());
}

// 清除发送区
void Test::on_pushButton_clearSend_clicked()
{
    ui->plainTextEdit_singleSend->clear();
}

// 接受数据
void Test::readData()
{
    if(!isMainWindowUse)
    {
        QByteArray buf;
        buf = serial.readAll();
        if(!buf.isEmpty())
        {
            ui->plainTextEdit_receiveDisplay->appendPlainText(buf);
        }
        buf.clear();
    }
}


// 清除接收区
void Test::on_pushButton_clearReceive_clicked()
{
    ui->plainTextEdit_receiveDisplay->clear();
}


// 主窗口调用发送数据
void Test::mainWinSend(QByteArray data)
{
    serial.write(data);
}


// 单次测量
void Test::slot_singleTest()
{
    qDebug() << isMainWindowUse << ' ' << "槽函数执行了";
    if(isMainWindowUse && isSingletest)
    {
        double R0 = 1, R01 = 2, R1 = 3, R2 = 4, Rx = 5;
        static QByteArray vis1, vis2;
        static int i = 0;
        vis1 = serial.readAll();       // 从串口读取数据放在vis1中
        if(i % 3 == 0 && i != 0)
        {
            if(i == 3)
                vis2 = vis1;            // 获得第一组测量数据的电桥状态
            if(vis2 != vis1)            // 获得每组第三次收到的数据与第一组的数据进行比较判断电桥是否平衡
            {
                emit testDone(R0, R01, R1, R2, Rx);       // 把一次测量的一组数据发送给主窗口数据展示区域
                return;
            }
        }
        serial.write("data");
        vis1.clear();
        i++;
    }
}

// 多次测量
void Test::slot_repeatTest()
{
    if(isMainWindowUse && !isSingletest)
    {
        double R0 = 1, R01 = 2, R1 = 3, R2 = 4, Rx = 5;
        static QByteArray vis1, vis2;
        static int i = 0;
        vis1 = serial.readAll();       // 从串口读取数据放在vis1中
        if(i % 3 == 0 && i != 0)
        {
            if(i == 3)
                vis2 = vis1;            // 获得第一组测量数据的电桥状态
            if(vis2 != vis1)            // 获得每组第三次收到的数据与第一组的数据进行比较判断电桥是否平衡
            {
                emit testDone(R0, R01, R1, R2, Rx);       // 把一次测量的一组数据发送给主窗口数据展示区域
                return;
            }
        }
        serial.write("data");
        vis1.clear();
        i++;
    }

}
