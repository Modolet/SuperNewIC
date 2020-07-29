#ifndef CHANGEPASSWD_H
#define CHANGEPASSWD_H

#if _MSC_VER >= 1600	// MSVC2015 > 1899,	MSVC_VER = 14.0
#pragma execution_character_set("utf-8")
#endif

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
                        Network* net = NULL);
  ~changePasswd();

 protected:
  void closeEvent(QCloseEvent* event);

 private slots:
  void on_pushButton_ok_clicked();

 private:
  Ui::changePasswd* ui;
  Network* net;
  int id;
  QWidget* parent;
};

#endif  // CHANGEPASSWD_H
