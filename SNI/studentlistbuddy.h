#ifndef STUDENTLISTBUDDY_H
#define STUDENTLISTBUDDY_H

#include <QWidget>
#include <QLabel>
#include <QEvent>
#include <QString>

class StudentListBuddy : public QWidget
{
    Q_OBJECT
public:
    explicit StudentListBuddy(QWidget *parent = nullptr);
    void initUi();//初始化UI
    QLabel  *name;//姓名
    QLabel  *id;//id
    QLabel  *sign;//签名
    QString sex;//性别
    QString classroom;//班级

signals:

public slots:

};

#endif // STUDENTLISTBUDDY_H
