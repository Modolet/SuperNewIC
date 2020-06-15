#ifndef STUDENTLISTBUDDY_H
#define STUDENTLISTBUDDY_H

#if _MSC_VER >= 1600	// MSVC2015 > 1899,	MSVC_VER = 14.0
#pragma execution_character_set("utf-8")
#endif

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
