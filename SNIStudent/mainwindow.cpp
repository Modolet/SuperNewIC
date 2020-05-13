#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    initMainWindow();           // 初始化窗口
    signalsToSlots();           // 设置信号和槽函数连接
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::signalsToSlots()                   // 把信号和槽函数连接起来
{
    // 如果测试窗口关闭，把isMainWindowUse设置为true
    connect(&testWin, &Test::destroyed, [&]{testWin.isMainWindowUse = true; qDebug()<< "哈六";});
    // 一次测量结束，把数据上传至数据库
    connect(&testWin, SIGNAL(testDone(double, double, double, double, double)), this, SLOT(upDataToTableView(double, double, double, double, double)));
}

void MainWindow::initMainWindow()                   // 初始化测试窗口，包含布局等
{
    QVBoxLayout *vLayout = new QVBoxLayout;         // 创建一个纵向布局
    vLayout->addWidget(ui->widget);                 // 把组件放在纵向布局里面
    vLayout->addWidget(&tableView);                 // 把数据展示的表放在纵向布局里面
    ui->page_resTest->setLayout(vLayout);           // 把测试页面设置为纵向布局
    tableView.horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);   // 设置展示的数据填满表格

    tableView.MainWin_setHandSubmit(true);      // 设置表格手动提交更新数据库
}

void MainWindow::on_pushButton_resTest_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_pushButton_errorAnalyse_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_pushButton_dataHandle_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
}

void MainWindow::on_pushButton_resValueRecorde_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);
}

void MainWindow::on_pushButton_testSpecific_clicked()
{
    testWin.setWindowModality(Qt::ApplicationModal);            // 模态窗口
    testWin.isMainWindowUse = false;
    testWin.show();                                             // 显示测试窗口
}

// 向主窗口展示数据部分增加一条记录
void MainWindow::upDataToTableView(double R0, double R01, double R1, double R2, double Rx)
{
    tableView.MainWin_addRecordToTable(R0, R01, R1, R2, Rx);    // 向显示数据表格中增加一条记录
    ui->radioButton_singleTest->setEnabled(true);               // 单次测量的选项恢复使能
    ui->radioButton_repeatTest->setEnabled(true);               // 多次测量的选项回复使能
}

// 判断单次测量还是多测测量
void MainWindow::on_pushButton_startTest_clicked()
{
    ui->radioButton_singleTest->setEnabled(false);               // 单次测量的选项消除使能
    ui->radioButton_repeatTest->setEnabled(false);               // 多次测量的选项消除使能

    if(ui->radioButton_singleTest->isChecked())                 // 如果单次测量被选中
    {
        testWin.isSingletest = true;                            // 把单次测量的标识设置为真
        testWin.slot_singleTest();                              // 执行单次测量的槽函数
    }
    else
    {
        testWin.isSingletest = false;
        testWin.slot_repeatTest();
    }
}

void MainWindow::on_pushButton_stopTest_clicked()
{

}
