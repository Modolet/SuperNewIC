#ifndef FIRST_H
#define FIRST_H

#include <QWidget>
#include <QRegExp>
#include <QMessageBox>
#include <QCryptographicHash>
#include <QByteArray>
#include <QCloseEvent>
#include "network.h"
#include "const.h"

namespace Ui {
class First;
}

class First : public QWidget
{
    Q_OBJECT

public:
    explicit First(QWidget *parent = nullptr,int id = 0,Network* net = nullptr);
    void initUI();
    ~First();

private slots:
    void on_pushButton_getVcode_clicked();
    void closeEvent(QCloseEvent *event);

    void on_pushButton_OK_clicked();

private:
    QWidget* parent;
    Ui::First *ui;
    Network* net;
    int id;
};

#endif // FIRST_H
