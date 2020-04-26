#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    // 初始化窗口
    initMainWindow();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::initMainWindow()
{
    //tableView.setParent(ui->page_resTest);
    QVBoxLayout *vLayout = new QVBoxLayout;
    vLayout->addWidget(ui->widget);
    vLayout->addWidget(&tableView);
    ui->page_resTest->setLayout(vLayout);
    tableView.horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    //tableView.move(0,100);
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
    testWin.setWindowModality(Qt::ApplicationModal);   // 模态窗口
    //testWin.setAttribute(Qt::WA_DeleteOnClose);        // 窗口关闭的时候释放内存
    testWin.show();
}

void MainWindow::on_pushButton_singleTest_clicked()
{

}
