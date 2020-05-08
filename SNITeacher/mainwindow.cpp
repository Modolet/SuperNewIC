#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent,network* socket): QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setFixedSize(this->width(),this->height());//固定窗口大小
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_shot_clicked()
{

}
