#include "stu_mainwindow.h"
#include "ui_stu_mainwindow.h"

Stu_MainWindow::Stu_MainWindow(QWidget *parent,Network* net)
    : QMainWindow(parent)
    , ui(new Ui::Stu_MainWindow)
{
    ui->setupUi(this);

    this->net = net;

    initMainWindow();                                                   // 初始化窗口
    signalsToSlots();                                                   // 设置信号和槽函数连接
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
    sqlTableMoedl = new Stu_SqlModel();                                     // 创建一个数据库可视化的模型
    ui->tableView_page_resTest->setModel(sqlTableMoedl->model);         // 把模型插入到堆栈窗口页面1的表格里面
    ui->tableView_page_dataAnalyse->setModel(sqlTableMoedl->model);     // 把模型插入到堆栈窗口页面3的表格里面

    ui->tableView_page_resTest->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);     // 设置展示的数据填满表格
    ui->tableView_page_dataAnalyse->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch); // 设置展示的数据填满表格

    ui->tableView_page_resTest->setEditTriggers(QAbstractItemView::NoEditTriggers);         // 设置表格数据不允许修改
    ui->tableView_page_dataAnalyse->setEditTriggers(QAbstractItemView::NoEditTriggers);     // 设置表格数据不允许修改

    get_average_variance_standardVariance();                        // 防止开始数据库有数据，所以计算均值和方差
}

void Stu_MainWindow::on_pushButton_user_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
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
