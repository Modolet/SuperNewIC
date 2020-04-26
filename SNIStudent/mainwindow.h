#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "test.h"
#include "tableview.h"

// 串口部分头文件
#include <QSerialPort>
#include <QSerialPortInfo>

// 添加布局相关的头文件
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QHeaderView>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_resTest_clicked();

    void on_pushButton_errorAnalyse_clicked();

    void on_pushButton_dataHandle_clicked();

    void on_pushButton_resValueRecorde_clicked();

    void on_pushButton_testSpecific_clicked();

    void on_pushButton_singleTest_clicked();

private:
    Ui::MainWindow *ui;
    Test testWin;
    TableView tableView;


private:
    void initMainWindow();

};
#endif // MAINWINDOW_H
