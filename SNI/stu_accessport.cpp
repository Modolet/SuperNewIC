#include "stu_accessport.h"
#include "ui_stu_accessport.h"

Stu_AccessPort::Stu_AccessPort(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Stu_AccessPort)
{
    ui->setupUi(this);
    timer = new QTimer(this);

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
    connect(&serial, &QSerialPort::readyRead, [=](){timer->start(10);});    // 接收硬件来的数据前等待100ms
    // 在测试专用下，一旦串口有数据进来就执行测试窗口的槽函数
    connect(timer, &QTimer::timeout, this, &Stu_AccessPort::readData);
    // 主窗口进行单次测量的时候，调用单次测量槽函数
    connect(timer, &QTimer::timeout, this, &Stu_AccessPort::slot_singleTest);
    // 主窗口进行单次测量的时候，调用多次测量槽函数
    connect(timer, &QTimer::timeout, this, &Stu_AccessPort::slot_repeatTest);
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
    if(ui->checkBox_16Send->isChecked())                                   // 16进制发送
    {
        QString str = ui->plainTextEdit_singleSend->toPlainText();
        int i, num;
        char data[1];
        for(i = 0; i < str.length(); i++)
        {
            if(i != 0 && i % 2 != 0)
            {
                num = str.mid(i - 1, 2).toInt(NULL, 16);
                data[0] = num;
                qDebug() << "num: " << num << "str1: " << str.mid(i - 1, 2);
                serial.write(data, 1);
            }
        }
        if(i % 2)
        {
            num = str.mid(i - 1, 1).toInt(NULL, 16);
            data[0] = num;
            qDebug() << i << "num: " << num << "str2: " << str.mid(i - 1, 2);
            serial.write(data, 1);
        }
    }
    else
        serial.write(ui->plainTextEdit_singleSend->toPlainText().toLatin1());
}

// 检查16进制输入的字符的时候是否有不规范的
void Stu_AccessPort::on_plainTextEdit_singleSend_textChanged()
{
    if(ui->checkBox_16Send->isChecked())
    {
        QString str = ui->plainTextEdit_singleSend->toPlainText();
        for(int i = 0; i < str.length(); i++)
            if(!((str[i] >= '0' && str[i] <= '9') || (str[i] >= 'a' && str[i] <= 'f') || (str[i] >= 'A' && str[i] <='F')))
            {
                ui->plainTextEdit_singleSend->clear();
                QMessageBox::warning(this, "提示", "请输入正确的格式0-9a-fA-F例5010");
                return;
            }
    }
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
            str_char += buf;
            qDebug() << "buf: " << buf ;

            for(int i = 0; i < buf.length(); i++)
            {
                if((int)buf.at(i) >= 0)
                {
                    str_16 += QString::number(buf.at(i), 16) + " ";
                    //qDebug() << "int" <<(int)buf.at(i) << "string" << QString::number(abs(buf.at(i)), 16);
                }
                else
                {
                    str_16 += QString::number(128 + 128 - abs(buf.at(i)), 16) + " ";
                     //qDebug() << "int" <<(int)buf.at(i) << "string" << QString::number(128 + 128 - abs(buf.at(i)), 16);
                }
            }

            if(ui->checkBox_16Show->isChecked())
                ui->plainTextEdit_receiveDisplay->setPlainText(str_16);
            else
                ui->plainTextEdit_receiveDisplay->setPlainText(str_char);
        }
        buf.clear();
    }
    timer->stop();
}

// 是否16进制显示
void Stu_AccessPort::on_checkBox_16Show_stateChanged(int arg1)
{
    if(ui->checkBox_16Show->isChecked())
        ui->plainTextEdit_receiveDisplay->setPlainText(str_16);
    else
        ui->plainTextEdit_receiveDisplay->setPlainText(str_char);
}

// 清除接收区
void Stu_AccessPort::on_pushButton_clearReceive_clicked()
{
    str_16.clear();
    str_char.clear();
    ui->plainTextEdit_receiveDisplay->setPlainText("");
}

// 主窗口调用发送数据
void Stu_AccessPort::mainWinSend(QByteArray data)
{
    serial.write(data);
}

// 判断电桥是否平衡
bool isBalance(QByteArray rec)
{
    if(!rec.isEmpty())
    {
        int int_rec = (int)rec.at(0);
        if(int_rec <= -1 && int_rec >= -128)
            return true;
    }
    return false;
}

// 单次测量
void Stu_AccessPort::slot_singleTest()
{
    if(isMainWindowUse && isSingletest)
    {
        int now = time % 3;                                     // 获得当前一组数据的第几次发送数据
        vis = serial.readAll();                                 // 从串口读取数据放在vis1中
        if(time % 3 == 0)
        {
            if(isBalance(vis))                                   // 现在只用判断最高位是否为1
            {
                if((index[0] >> 5) & 1)                         // 0010 0000
                {
                    R01 = getR0(index[1], index[2]);
                    R01 = 10 / (1 - R01 / pow(2, 16));          // 计算R0的公式
                    emit  testDone(R0, R01, sqrt(R0 * R01));
                    circuitReset();                             // 电路参数归零
                    return;
                }
                else
                {
                    R0 = getR0(index[1], index[2]);
                    R0 = 10 / (1 - R0 / pow(2, 16));
                }

                index[0] = index[0] + 0x20;                     // 电桥反转 +0010 0000
                index[1] = 0; index[2] = 0;                     // 一次测量完成后，控制R0的数值全部归零
            }
            else if(time == 3)
                index[0] += 0x40;                                // 0100 0000
            else
            {
                index[2]++;
                if(index[2] > 0xFF)
                {
                    index[1]++;
                    index[2] = 0;
                    if(index[2] > 0xFF)
                    {
                        QMessageBox::information(this, "提示", "电桥一直未平衡！");
                        return ;
                    }
                }
            }
        }
        char dataOfSend[1] = {(char)index[now]};
        serial.write(dataOfSend, 1);
        if(time == 3)
            index[0] -= 0x40;
        time++;
        vis.clear();
    }
    timer->stop();
}

// 多次测量
void Stu_AccessPort::slot_repeatTest()
{
    timer->stop();
}

// 电桥平衡时，把控制R0的那20位二进制串转化为十进制数
int Stu_AccessPort::getR0(int i0, int i1)
{
    QString str_16 = QString::number(i0, 16) + QString::number(i1, 16);
    int int_10 = str_16.toInt(NULL, 16);                   // 十六进制字符串转为十进制数。如2b5f67H->2842471
    return int_10;
}

// 电路参数归零
void Stu_AccessPort::circuitReset()
{
    time = 0;
    for(int i = 0; i < 3; i++)          // 一次测量完成后，控制R0的数值全部归零
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


