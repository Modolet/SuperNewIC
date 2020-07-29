#ifndef STU_MAINWINDOW_H
#define STU_MAINWINDOW_H

#if _MSC_VER >= 1600	// MSVC2015 > 1899,	MSVC_VER = 14.0
#pragma execution_character_set("utf-8")
#endif

#include <QMainWindow>
#include <QImage>
#include <QIcon>
#include <QPixmap>
#include <QMenu>
#include <QAction>

#include <QtCore/qmath.h>

#include "stu_accessport.h"
#include "stu_sqlmodel.h"
#include "changeusericon.h"
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

    void slot_changeIcon();
    void slot_updateIcon(QPixmap catureImage,QString format);
    void slot_changeSign();
    void slot_updateSign();

    void on_pushButton_showDataConect_clicked();

    void on_pushButton_reset_clicked();

private:
    Ui::Stu_MainWindow *ui;
    Stu_AccessPort testWin;
    Stu_SqlModel *sqlTableMoedl;
    Network* net;
     QIcon* icon;
    //菜单
    QMenu* iconMenu;
    QMenu* settingMenu;
    QMenu* t_style;//二级菜单：主题

    //编辑
    QLineEdit* le_sign;

private:
    void initMainWindow();
    void initMenu();                //初始化菜单
    void getInfo();

};
#endif // STU_MAINWINDOW_H
