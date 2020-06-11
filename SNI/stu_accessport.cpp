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

void Stu_AccessPort::findSerial()                 // 查找计算机可用串口
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

void Stu_AccessPort::initSerials()                                                // 初始化串口
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
    index++;            // 没有用
    serial.setPortName(ui->comboBox_serialSelect->currentText());
}
// 如果串口当前选择波特率改变，串口波特率设置为改变后的值
void Stu_AccessPort::on_comboBox_baudRate_currentIndexChanged(int index)
{
    index++;
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
/*
void Test::slot_singleTest()
{
    if(isMainWindowUse && isSingletest)
    {
        int now = time % 3;                         // 获得当前一组数据的第几次发送数据
        QByteArray dataOfSend = data[index[now]] + data[index[now + 1]];    // 获得当前要发送的数据
        vis1 = serial.readAll();                    // 从串口读取数据放在vis1中
        if(time % 3 == 0 && time != 0)
        {
            if(time == 3)
                vis2 = vis1;            // 获得第一组测量数据的电桥状态
            if(vis2 != vis1)            // 获得每组第三次收到的数据与第一组的数据进行比较判断电桥是否平衡
            {
                if(isR0)
                {
                    R0 = 1;
                    isR0 = false;
                }
                else
                {
                    R01 = 1;
                    double Rx = 1;
                    emit testDone(R0, R01, Rx);       // 把一次测量的一组数据发送给主窗口数据展示区域
                    time = 0;
                }

                index[2] = 0; index[3] = 0; index[4] = 0; index[5] = 0;

                index[1]++;             // 电路状态换一次
                if(index[1] >= 0)
                {
                    index[1] = 0;
                    index[0]++;
                    if(index[0] >= 16)
                    {
                        QMessageBox::warning(this, "error", "电路一直未平衡");
                        return;
                    }
                }
                return;
            }
            index[5]++;
            if(index[5] >= 16)
            {
                index[5] = 0;
                index[4]++;
                if(index[4] >= 16)
                {
                    index[4] = 0;
                    index[3]++;
                    if(index[3] >= 16)
                    {
                        index[3] = 0;
                        index[2]++;
                        if(index[2] >= 16)
                        {
                            QMessageBox::warning(this, "error", "电桥一直未平衡");
                            return;
                        }
                    }
                }
            }
        }
        serial.write(dataOfSend);
    }
}
*/

// 单次测量
void Stu_AccessPort::slot_singleTest()
{
    if(isMainWindowUse && isSingletest)
    {
        int now = time % 3;                         // 获得当前一组数据的第几次发送数据
        vis = serial.readAll();                     // 从串口读取数据放在vis1中
        if(time % 3 == 0)
        {
            if(vis == "01")
            {
                index[0] = index[0] + 0x2;           // 电桥反转 +0010
                time = 6;

                if((index[0]>>2)&1)
                {
                    // R01 = index[0]......;
                    emit  testDone(R0, R01, sqrt(R0 * R01));
                    time = 0;
                }
                else
                // R0 = index[0]......;
                    ;
                for(int i = 1; i < 6; i++)          // 一次测量完成后，控制R0的数值全部归零
                    index[i] = 0;
            }
            else if(time == 3)
                index[0] += 4;           // 0100
            else
            {
                index[5] += 2;
                for(int i = 5; i > 0; i++)
                    if(index[i] >= 16)
                    {
                        index[i] = 0;
                        index[i - 1]++;
                    }
                if(index[0]&1 && index[1] == 15 && index[2] == 15 && index[3] == 15 && index[4] == 15 && index[5] == 15)    // 0001 1111   1111
                {
                    QMessageBox::warning(this, "提示", "电桥一直未平衡！");
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
    /*
    if(isMainWindowUse && !isSingletest)
    {
        firstData = data[i1] + data[i2];
        vis1 = serial.readAll();       // 从串口读取数据放在vis1中
        if(time % 3 == 0 && time != 0)
        {
            if(time == 3)
                vis2 = vis1;            // 获得第一组测量数据的电桥状态
            if(vis2 != vis1)            // 获得每组第三次收到的数据与第一组的数据进行比较判断电桥是否平衡
            {
                emit testDone(R0, R01, R1, R2, Rx);       // 把一次测量的一组数据发送给主窗口数据展示区域
                return;
            }
        }
        switch(time % 3)
        {
            case 0:
                serial.write(firstData);
                i2++;
                if(i2 >= 16)
                {
                    i2 = 0;
                    i1++;
                }
                break;
            case 1:
                serial.write(firstData);
                k2++;
                if(k2 >= 16)
                {
                    k2 = 0;
                    k1++;
                }
                break;
            case 2:
                serial.write(firstData);
                j2++;
                if(j2 >= 16)
                {
                    j2 = 0;
                    j1++;
                }
                break;
        }

        vis1.clear();
        time++;
    }
    */

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
0010000 	00000000		000000000	采集此时收回的数据（前两次发送数据后读取的数据需要丢弃）
0010000		00000000		000000010	采集此时收回的数据
0010000		00000000		000000100	采集此时收回的数据
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
