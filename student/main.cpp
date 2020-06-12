#include "stu_mainwindow.h"

#include <QApplication>

int ex_id;  //全局储存id

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Stu_MainWindow w;
    w.show();
    return a.exec();
}
