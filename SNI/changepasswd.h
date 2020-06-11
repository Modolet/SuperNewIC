#ifndef CHANGEPASSWD_H
#define CHANGEPASSWD_H

#include <QCloseEvent>
#include <QString>
#include <QWidget>

#include "network.h"

namespace Ui {
class changePasswd;
}

class changePasswd : public QWidget {
  Q_OBJECT

 public:
  explicit changePasswd(QWidget* parent = nullptr, int id = 0,
                        network* net = NULL);
  ~changePasswd();

 protected:
  void closeEvent(QCloseEvent* event);

 private slots:
  void on_pushButton_ok_clicked();

 private:
  Ui::changePasswd* ui;
  network* net;
  int id;
  QWidget* parent;
};

#endif  // CHANGEPASSWD_H
