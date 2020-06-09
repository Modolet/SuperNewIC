#ifndef STUDENTLISTBUDDY_H
#define STUDENTLISTBUDDY_H

#include <QWidget>
#include <QLabel>
#include <QEvent>

class StudentListBuddy : public QWidget
{
    Q_OBJECT
public:
    explicit StudentListBuddy(QWidget *parent = nullptr);
    void initUi();//初始化UI
    QLabel *name;//姓名
    QLabel *sign;//签名

signals:

public slots:

};

#endif // STUDENTLISTBUDDY_H
