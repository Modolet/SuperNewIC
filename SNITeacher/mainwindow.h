#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QList>
#include <QMainWindow>
#include <QString>
#include <QImage>
#include <QIcon>
#include <QPixmap>
#include <QMenu>
#include <QAction>
#include <QMessageBox>
#include <synchapi.h>

#include "const.h"
#include "network.h"
#include "changeusericon.h"

extern int ex_id;


QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget* parent = nullptr, network* net = 0);
    ~MainWindow();

private slots:


    void on_toolButton_icon_clicked();
    void slot_style_1();
    void slot_style_2();
    void slot_style_3();
    void slot_viewAll();
    void slot_about();
    void slot_changeIcon();
    void slot_updateIcon(QPixmap catureImage,QString format);


private:
    Ui::MainWindow* ui;
    network* net;
    QIcon* icon;
    QFile* theme;
    void initMenu();//初始化菜单
    void getInfo();
    void setqss(int id);
    //菜单
    QMenu* iconMenu;
    QMenu* t_style;//二级菜单：主题
    QMenu* settingMenu;

};
#endif  // MAINWINDOW_H
