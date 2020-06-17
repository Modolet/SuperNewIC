#ifndef STU_MAINWINDOW_H
#define STU_MAINWINDOW_H

#if _MSC_VER >= 1600	// MSVC2015 > 1899,	MSVC_VER = 14.0
#pragma execution_character_set("utf-8")
#endif

#include <QMainWindow>
// 串口部分头文件
#include <QSerialPort>
#include <QSerialPortInfo>

// 添加布局相关的头文件
#include <QHBoxLayout>
#include <QVBoxLayout>

#include <QtCore/qmath.h>

#include "stu_accessport.h"
#include "stu_sqlmodel.h"
#include "network.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Stu_MainWindow; }
QT_END_NAMESPACE

class Stu_MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    Stu_MainWindow(QWidget* parent = nullptr,Network* = nullptr);
    ~Stu_MainWindow();

    void signalsToSlots();                                  // 设置信号和槽函数连接

signals:

private slots:
    void on_pushButton_resTest_clicked();

    void on_pushButton_resValueRecorde_clicked();

    void on_pushButton_testSpecific_clicked();

    void on_pushButton_startTest_clicked();

    void on_pushButton_stopTest_clicked();

    void on_pushButton_deleteData_clicked();

    void on_pushButton_clearAll_clicked();

    void upDataToTableView(double, double, double);         // 增加一条记录到主窗口展示区域

    void get_average_variance_standardVariance();           // 获取均值方差标准差

    void on_pushButton_notice_clicked();

    void on_pushButton_user_clicked();

private:
    Ui::Stu_MainWindow *ui;
    Stu_AccessPort testWin;
    Stu_SqlModel *sqlTableMoedl;
    Network* net;

private:
    void initMainWindow();

};
#endif // STU_MAINWINDOW_H
