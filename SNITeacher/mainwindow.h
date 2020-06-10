#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QList>
#include <QMainWindow>
#include <QString>

#include "const.h"
#include "network.h"

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


private:
    Ui::MainWindow* ui;
    network* net;
    void getInfo();
};
#endif  // MAINWINDOW_H
