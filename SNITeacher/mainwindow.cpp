#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFile>
#include <QString>
#include <QIcon>
#include <QDebug>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    initQss(3);//设置qss风格
    initIcons();//初始化图标
    initWindow();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::initWindow()
{
    //这里是让表格表头均分
    ui->tableWidget_score->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableWidget_list->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableWidget_notice->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
//    connect(ui->listWidget,SIGNAL(currentRowChanged(int)),ui->stackedWidget,SLOT(setCurrentIndex(int)));
    //下面是信号和槽
    connect(ui->style1,SIGNAL(triggered()),this,SLOT(on_style1_triggered()));
    connect(ui->style2,SIGNAL(triggered()),this,SLOT(on_style2_triggered()));
    connect(ui->style3,SIGNAL(triggered()),this,SLOT(on_style3_triggered()));
    connect(ui->style4,SIGNAL(triggered()),this,SLOT(on_style4_triggered()));
    connect(ui->style5,SIGNAL(triggered()),this,SLOT(on_style5_triggered()));
    connect(ui->style6,SIGNAL(triggered()),this,SLOT(on_style6_triggered()));
}

void MainWindow::initQss(int n)
{
    QString str_file;
    switch (n) {
    case 1:
        str_file = ":/qss/style01.qss";
        break;
    case 2:
        str_file = ":/qss/style02.qss";
        break;
    case 3:
        str_file = ":/qss/style03.qss";
        break;
    case 4:
        str_file = ":/qss/style04.qss";
        break;
    case 5:
        str_file = ":/qss/style05.qss";
        break;
    case 6:
        str_file = ":/qss/style06.qss";
        break;

    }
    QFile f_qss(str_file);
    f_qss.open(QFile::ReadOnly);
    QString s_qss = QLatin1String(f_qss.readAll());
    qApp->setStyleSheet(s_qss);
    f_qss.close();
}

void MainWindow::initIcons()
{
    p_icon = new QIcon;
    p_icon->addFile(":/icon/list.png");
    ui->pushButton_list->setIcon(*p_icon);
    p_icon->addFile(":/icon/score.png");
    ui->pushButton_score->setIcon(*p_icon);
    p_icon->addFile(":/icon/status.png");
    ui->pushButton_status->setIcon(*p_icon);
    p_icon->addFile(":/icon/message.png");
    ui->pushButton_message->setIcon(*p_icon);
    p_icon->addFile(":/icon/notice.png");
    ui->pushButton_notice->setIcon(*p_icon);
}

void MainWindow::on_pushButton_list_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_pushButton_notice_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_pushButton_status_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_pushButton_message_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
}

void MainWindow::on_pushButton_score_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);
}

void MainWindow::on_style1_triggered()
{
    initQss(1);
    qDebug() << "style01";
}

void MainWindow::on_style2_triggered()
{
    initQss(2);
}

void MainWindow::on_style3_triggered()
{
    initQss(3);
}

void MainWindow::on_style4_triggered()
{
    initQss(4);
}

void MainWindow::on_style5_triggered()
{
    initQss(5);
}

void MainWindow::on_style6_triggered()
{
    initQss(6);
}
