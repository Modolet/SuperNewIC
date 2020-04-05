#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

struct data
{
    int style;
};

class QIcon;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_list_clicked();
    void on_pushButton_notice_clicked();
    void on_pushButton_status_clicked();
    void on_pushButton_message_clicked();
    void on_pushButton_score_clicked();
    void on_style1_triggered();
    void on_style2_triggered();
    void on_style3_triggered();
    void on_style4_triggered();
    void on_style5_triggered();
    void on_style6_triggered();

private:
    QIcon* p_icon;
    struct data sc_data;
    Ui::MainWindow *ui;
    void initWindow();
    void initQss(int n);
    void initIcons();
    void dataRead();
    void dataWrite();
    void dataSet();//读取文件配置
};
#endif // MAINWINDOW_H
