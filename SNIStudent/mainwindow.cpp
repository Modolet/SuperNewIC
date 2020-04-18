#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
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
