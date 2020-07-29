#include "stu_mainwindow.h"
#include "ui_stu_mainwindow.h"

#include <QFileDialog>
#include <QToolButton>
#include <QImageReader>


Stu_MainWindow::Stu_MainWindow(QWidget *parent,Network* net)
    : QMainWindow(parent)
    , ui(new Ui::Stu_MainWindow)
{
    ui->setupUi(this);

    this->net = net;
    getInfo();
    initMainWindow();                                                   // 初始化窗口
    initMenu();
    signalsToSlots();                                                   // 设置信号和槽函数连接
    ui->toolButton_icon->setStyleSheet("QToolButton::menu-indicator{image:none;}");
}

Stu_MainWindow::~Stu_MainWindow()
{
    delete ui;
}

void Stu_MainWindow::signalsToSlots()                                       // 把信号和槽函数连接起来
{
    // 一次测量结束，把数据上传至数据库
    connect(&testWin, &Stu_AccessPort::testDone, this, &Stu_MainWindow::upDataToTableView);
}

void Stu_MainWindow::initMainWindow()                                       // 初始化测试窗口，包含布局等
{
    qDebug() << "initWindow" ;
    sqlTableMoedl = new Stu_SqlModel(this,net);                                     // 创建一个数据库可视化的模型
    qDebug() << "initsqlmodel";
    ui->tableView_page_resTest->setModel(sqlTableMoedl->model);         // 把模型插入到堆栈窗口页面1的表格里面
    ui->tableView_page_dataAnalyse->setModel(sqlTableMoedl->model);     // 把模型插入到堆栈窗口页面3的表格里面
    qDebug() << "initsqlmodel success";

    ui->tableView_page_resTest->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);     // 设置展示的数据填满表格
    ui->tableView_page_dataAnalyse->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch); // 设置展示的数据填满表格

    ui->tableView_page_resTest->setEditTriggers(QAbstractItemView::NoEditTriggers);         // 设置表格数据不允许修改
    ui->tableView_page_dataAnalyse->setEditTriggers(QAbstractItemView::NoEditTriggers);     // 设置表格数据不允许修改

    get_average_variance_standardVariance();                        // 防止开始数据库有数据，所以计算均值和方差
}

void Stu_MainWindow::getInfo()
{
    qDebug() << "getinfo1";
    //获取教师信息
    info sc_info = net->getInfo();
    ui->label_name->setText(sc_info.name);
    ui->label_sign->setText(sc_info.sign);
    if(sc_info.image.size() == 0)
    {
        icon = new QIcon(":/Icon/studenticon.jpg");
        ui->toolButton_icon->setIcon(*icon);
        ui->toolButton_icon->setIconSize(QSize(50,50));
    }
    else
    {
        //将QByteArray转为QImageReader
        QBuffer buffer(&sc_info.image);
        buffer.open(QIODevice::ReadOnly);
        QImageReader reader(&buffer,sc_info.format.toStdString().c_str());
        qDebug() << sc_info.format;
        QImage img = reader.read();
        qDebug() << buffer.size();
        //设置头像和大小
        ui->toolButton_icon->setIcon(QPixmap::fromImage(img));
        ui->toolButton_icon->setIconSize(this->size());
    }

    this->setWindowTitle(sc_info.name);
    qDebug() << "getinfo2";
}

void Stu_MainWindow::initMenu()
{
    iconMenu = new QMenu();

    QAction* changeIcon = new QAction("修改头像",this);
    QAction* changeSign = new QAction("修改签名",this);

    iconMenu->addAction(changeIcon);
    iconMenu->addAction(changeSign);

    //添加到按钮
    ui->toolButton_icon->setMenu(iconMenu);
    ui->toolButton_icon->setPopupMode(QToolButton::InstantPopup);

    //信号和槽

    connect(changeIcon,&QAction::triggered,this,&Stu_MainWindow::slot_changeIcon);
    connect(changeSign,&QAction::triggered,this,&Stu_MainWindow::slot_changeSign);
}


void Stu_MainWindow::slot_changeIcon()
{
    QFile* imgFile = new QFile(QFileDialog::getOpenFileName(nullptr,"请选择头像文件",nullptr,"图像文件（*.BMP *.GIF *.JPG *.JPEG *.PNG *.PBN *.PGM *.PPM *.XBM *.XPM"));
    if(imgFile->fileName() == NULL)
        return;
    else
    {
        ChangeUserIcon* ci = new ChangeUserIcon(this,imgFile);
        connect(ci,&ChangeUserIcon::signalCompleteCature,this,&Stu_MainWindow::slot_updateIcon);
        ci->show();

    }
}

void Stu_MainWindow::slot_updateIcon(QPixmap catureImage, QString format)
{
    if(catureImage.size().width() <= 50)
    {
        QMessageBox::warning(this,"错误","您选择的图片过小！请选择分辨率大于50x50的图片！");
        return;
    }
    //将图片转为QByteArray
    QBuffer buffer;
    QByteArray* pixArray = new QByteArray;
    buffer.open(QIODevice::ReadWrite);
    catureImage.save(&buffer,format.toStdString().c_str());
    pixArray->append(buffer.data());
    if(net->updateIcon(ex_id,pixArray,format))
    {
        QMessageBox::information(this,"提示","修改成功！");
        ui->toolButton_icon->setIcon(QIcon(catureImage));
    }
}

void Stu_MainWindow::slot_changeSign()
{
    le_sign = new QLineEdit(this);
    connect(le_sign,&QLineEdit::editingFinished,this,&Stu_MainWindow::slot_updateSign);
    le_sign->setGeometry(65,35,165,20);
    le_sign->show();
    le_sign->setText(ui->label_sign->text());
    le_sign->selectAll();
    le_sign->setFocus();
}

void Stu_MainWindow::slot_updateSign()
{
    QString sign = le_sign->text();
    le_sign->hide();
    if(net->updateSign(sign))
    {
        ui->label_sign->setText(sign);
    }
    else
    {
        QMessageBox::warning(this,"错误","数据传输出现错误！请检查网络连接后重试！");
    }
}


void Stu_MainWindow::on_pushButton_notice_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void Stu_MainWindow::on_pushButton_resTest_clicked()                    // 堆栈窗口选择显示
{
    ui->stackedWidget->setCurrentIndex(2);
}

void Stu_MainWindow::on_pushButton_resValueRecorde_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
}

void Stu_MainWindow::on_pushButton_testSpecific_clicked()
{
    testWin.setWindowModality(Qt::ApplicationModal);                // 模态窗口
    testWin.isMainWindowUse = false;
    testWin.show();                                                 // 显示测试窗口
}

void Stu_MainWindow::on_pushButton_startTest_clicked()              // 判断单次测量还是多测测量
{
    testWin.isMainWindowUse = true;
    ui->radioButton_singleTest->setEnabled(false);                  // 开始单次测量后，就不能在的选择测量模式知道测量完毕
    ui->radioButton_repeatTest->setEnabled(false);                  // 多次测量的选项消除使能
    if(ui->radioButton_singleTest->isChecked())                     // 如果单次测量被选中
    {
        testWin.isSingletest = true;                                // 把单次测量的标识设置为真
        testWin.slot_singleTest();                                  // 执行单次测量的槽函数
    }
    else
    {
        testWin.isSingletest = false;
        testWin.slot_repeatTest();
    }
}

void Stu_MainWindow::upDataToTableView(double R0, double R01, double Rx)// 向主窗口展示数据部分增加一条记录
{
    sqlTableMoedl->MainWin_addRecordToTable(R0, R01, Rx);           // 向显示数据表格中增加一条记录
    ui->radioButton_singleTest->setEnabled(true);                   // 单次测量的选项恢复使能
    ui->radioButton_repeatTest->setEnabled(true);                   // 多次测量的选项回复使能
    get_average_variance_standardVariance();                        // 获得了一条数据重新计算均值和方差
    sqlTableMoedl->model->submitAll();                              // 提交
}

void Stu_MainWindow::on_pushButton_stopTest_clicked()
{

}

void Stu_MainWindow::on_pushButton_deleteData_clicked()                 // 删除当前选中的记录
{
    QItemSelectionModel *selectModel = ui->tableView_page_dataAnalyse->selectionModel(); // 获取选中的模型
    QModelIndexList list = selectModel->selectedRows();             // 取出模型中的索引
    for(int i = 0; i < list.size(); i++)                            // 删除所有选中的行
        sqlTableMoedl->model->removeRow( list.at(i).row() );        // 删除此行记录
    get_average_variance_standardVariance();                        // 计算均值方差标准差
    sqlTableMoedl->model->submitAll();                              // 提交删除
}

void Stu_MainWindow::on_pushButton_clearAll_clicked()               // 清除所有测得的所有数据
{
    int lastRow = sqlTableMoedl->model->rowCount();                 // 获取表中最后一行
    for(int i = lastRow - 1; i >= 0; i--)                           // 从第一行删除到最后一行
        sqlTableMoedl->model->removeRow(i);                         // 删除此行记录
    get_average_variance_standardVariance();                        // 计算均值和方差
    sqlTableMoedl->model->submitAll();                              // 提交删除
}

void Stu_MainWindow::get_average_variance_standardVariance()                    // 计算均值和方差
{
    double average = 0, variance = 0, standardVariance = 0;
    int rows = sqlTableMoedl->model->rowCount();                                // 获取总行数
    if(rows != 0)
    {
        for(int i = 0; i < rows; i++)
        {
            average += sqlTableMoedl->model->record(i).value("Rx").toDouble();
            QSqlRecord record = sqlTableMoedl->model->record(i);
            record.setValue("实验次数", i + 1);
            sqlTableMoedl->model->setRecord(i, record);
        }
        average = average / rows;                                               // 获得均值

        for(int i = 0; i < rows; i++)
        {
            double value = sqlTableMoedl->model->record(i).value("Rx").toDouble();
            variance += (value - average) * (value - average);
        }
        variance /= rows;                                                       // 获得方差
        standardVariance = sqrt(variance);                                      // 获得标准差
    }
    ui->lineEdit_averageValue->setText(QString::number(average, 10, 4));        // 把数据插入到主窗口显示区
    ui->lineEdit_variance->setText(QString::number(variance, 10, 4));
    ui->lineEdit_standardDeviation->setText(QString::number(standardVariance, 10, 4));
}

void Stu_MainWindow::on_pushButton_showDataConect_clicked()
{
    testWin.showDataWidge->show();
}

void Stu_MainWindow::on_pushButton_reset_clicked()
{
    testWin.circuitReset();
}
