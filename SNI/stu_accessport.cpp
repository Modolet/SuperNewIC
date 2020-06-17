#include "stu_accessport.h"
#include "ui_stu_accessport.h"

Stu_AccessPort::Stu_AccessPort(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Stu_AccessPort)
{
    ui->setupUi(this);

    findSerial();               // 获取有用或者闲置端口，并且添加到串口选择下拉框
    initSerials();              // 初始化串口，设置波特率，停止位...
    signalsToSlots();
    ui->checkBox_openSerial->setCheckState(Qt::Checked);    // 打开窗口选中
}

Stu_AccessPort::~Stu_AccessPort()
{
    delete ui;
}


void Stu_AccessPort::signalsToSlots()             // 把信号和槽函数连接起来
{
    // 在测试专用下，一旦串口有数据进来就执行测试窗口的槽函数
    connect(&serial, &QSerialPort::readyRead, this, &Stu_AccessPort::readData);
    // 主窗口进行单次测量的时候，调用单次测量槽函数
    connect(&serial, &QSerialPort::readyRead, this, &Stu_AccessPort::slot_singleTest);
    // 主窗口进行单次测量的时候，调用多次测量槽函数
    connect(&serial, &QSerialPort::readyRead, this, &Stu_AccessPort::slot_repeatTest);
}

void Stu_AccessPort::findSerial()                 // 查找计算机可用串口，并生成列表放在ui界面的串口选择下拉框
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

void Stu_AccessPort::initSerials()                                      // 初始化串口
{
    serial.setPortName(ui->comboBox_serialSelect->currentText());       // 设置串口名
    serial.setBaudRate(ui->comboBox_baudRate->currentText().toInt());   // 设置波特率
    serial.setStopBits(QSerialPort::OneStop);                           // 设置停止位
    serial.setDataBits(QSerialPort::Data8);                             // 设置数据位
    serial.setParity(QSerialPort::NoParity);                            // 设置校验位
    serial.setFlowControl(QSerialPort::NoFlowControl);                  // 设置流控制
}


// 如果串口当前选择端口名改变，串口端口名设置为改变后的值
void Stu_AccessPort::on_comboBox_serialSelect_currentIndexChanged(int index)
{
    index++;            // 这里index用不到，只是想避免警告
    serial.setPortName(ui->comboBox_serialSelect->currentText());
}
// 如果串口当前选择波特率改变，串口波特率设置为改变后的值
void Stu_AccessPort::on_comboBox_baudRate_currentIndexChanged(int index)
{
    index++;            // 这里index用不到，只是想避免警告
    serial.setBaudRate(ui->comboBox_baudRate->currentText().toInt());
}

// 如果串口当前选择停止位位改变，串口停止位设置为改变后的值
void Stu_AccessPort::on_comboBox_stopBits_currentIndexChanged(int index)
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
void Stu_AccessPort::on_comboBox_dataBits_currentIndexChanged(int index)
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
void Stu_AccessPort::on_comboBox_parity_currentIndexChanged(int index)
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
void Stu_AccessPort::on_checkBox_openSerial_stateChanged(int arg1)
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
void Stu_AccessPort::on_comboBox_serialSelect_currentTextChanged(const QString &arg1)
{
    serial.close();
    serial.setPortName(arg1);
    if(ui->checkBox_openSerial->checkState() == Qt::Checked)
        serial.open(QIODevice::ReadWrite);
}


// 发送
void Stu_AccessPort::on_pushButton_send_clicked()
{
    serial.write(ui->plainTextEdit_singleSend->toPlainText().toLatin1());
}

// 清除发送区
void Stu_AccessPort::on_pushButton_clearSend_clicked()
{
    ui->plainTextEdit_singleSend->clear();
}

// 接受数据
void Stu_AccessPort::readData()
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
void Stu_AccessPort::on_pushButton_clearReceive_clicked()
{
    ui->plainTextEdit_receiveDisplay->clear();
}


// 主窗口调用发送数据
void Stu_AccessPort::mainWinSend(QByteArray data)
{
    serial.write(data);
}

// 单次测量
void Stu_AccessPort::slot_singleTest()
{
    if(isMainWindowUse && isSingletest)
    {
        int now = (time % 3) * 2;                           // 获得当前一组数据的第几次发送数据
        vis = serial.readAll();                             // 从串口读取数据放在vis1中
        if(time % 3 == 0)
        {
            if(vis == "01")
            {
                index[0] = index[0] + 0x2;                  // 电桥反转 +0010

                if((index[0]>>2)&1)
                {
                    R01 = getR0(index[0], index[1], index[2], index[3], index[4], index[5]);
                    R01 = 10 / (1 - R01 / pow(2, 16));          // 计算R0的公式
                    emit  testDone(R0, R01, sqrt(R0 * R01));
                    circuitReset();                             // 电路参数归零
                    return;
                }
                else
                {
                    R0 = getR0(index[0], index[1], index[2], index[3], index[4], index[5]);
                    R0 = 10 / (1 - R0 / pow(2, 16));
                }
                for(int i = 1; i < 6; i++)              // 一次测量完成后，控制R0的数值全部归零
                    index[i] = 0;
            }
            else if(time == 3)
                index[0] += 0x4;                    // 0100
            else
            {
                index[5] += 2;
                for(int i = 5; i > 0; i--)
                    if(index[i] >= 16)
                    {
                        index[i] = 0;
                        index[i - 1]++;
                    }
                if(index[0]&1 && index[1] == 15 && index[2] == 15 && index[3] == 15 && index[4] == 15 && index[5] == 15)    // 0001 1111   1111
                {
                    QMessageBox::information(this, "提示", "电桥一直未平衡！");
                    return ;
                }
            }
        }
        QByteArray dataOfSend = data[index[now]] + data[index[now + 1]];    // 获得当前要发送的数据
        serial.write(dataOfSend);
        if(time == 3)
            index[0] -= 4;
        time++;
        vis.clear();
    }
}

// 多次测量
void Stu_AccessPort::slot_repeatTest()
{

}

// 电桥平衡时，把控制R0的那20位二进制串转化为十进制数
int Stu_AccessPort::getR0(int i0, int i1, int i2, int i3, int i4, int i5)
{
    QString str_16 = QString::number(i0, 16) + QString::number(i1, 16) + QString::number(i2, 16) + QString::number(i3, 16) + QString::number(i4, 16) + QString::number(i5, 16);
    int int_10 = str_16.toInt(NULL, 16);                   // 十六进制字符串转为十进制数。如2b5f67H->2842471
    QString str_2 = QString::number(int_10, 2);            // 十进制数转为二进制串，如2842471->"1010110101111101100111"
    QString str_2_eff = str_2.mid(str_2.length()-21, 20);  // 截取控制R0的那20位二进制串，即倒数21位到倒数第1位之间的长度，如"1010110101111101100111"->"01011010111110110011"
    int int_10_eff = str_2_eff.toInt(NULL, 2);             // 把那20位二进制串转化为10进制数，如"01011010111110110011"->372659
    return int_10_eff;
}

// 电路参数归零
void Stu_AccessPort::circuitReset()
{
    time = 0;
    for(int i = 0; i < 6; i++)          // 一次测量完成后，控制R0的数值全部归零
        index[i] = 0;
    vis.clear();
}


/*
                                            数据收发格式
*********************************************************************************************************
                                        目前先做简单的（单次测量）
假定：并行数据位宽24位，8位51单片机分三组发送
第1，2位控制数字电位器（即滑丝电阻器）
第3位控制继电器（控制电桥切换）
第4-23位控制DAC（20位DAC）
*********************************************************************************************************
第一组                       第二组	                第三组
0000 0000                0000 0000                  0000 0000



*********************************************************************************************************
            单次测量：（单次测量可以不用调节数字电位器，即第1，2位，假定发00），继电器选择一种连接模式
00100000 	00000000		000000000	采集此时收回的数据（前两次发送数据后读取的数据需要丢弃）
00100000	00000000		000000010	采集此时收回的数据
00100000	00000000		000000100	采集此时收回的数据
        .
        .
直到收回数据01（标志位）（01ox代表电桥平衡，00ox代表电桥非平衡）
*************************************************************************************************************************************************************************************************
            单次测量，切换电桥桥臂：
0000000 	00000000		000000000	采集此时收回的数据
0000000		00000000		000000010	采集此时收回的数据
0000000		00000000		000000100	采集此时收回的数据
        .
        .
直到收回数据01（标志位）（01ox代表电桥平衡，00ox代表电桥非平衡）
*/
