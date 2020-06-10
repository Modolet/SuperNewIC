#include <QApplication>
#include <QDebug>

#include "login.h"
#include "mainwindow.h"

int ex_id;  //全局储存id
int main(int argc, char* argv[]) {
  QApplication a(argc, argv);
  // a.setQuitOnLastWindowClosed(false);
  QString qss;
  QFile qssFile(":/qss/list.qss");
  qssFile.open(QFile::ReadOnly);

  if (qssFile.isOpen()) {
    qss = QLatin1String(qssFile.readAll());
    qApp->setStyleSheet(qss);
    qssFile.close();
  }
  Login* l = new Login;
  return a.exec();
}
