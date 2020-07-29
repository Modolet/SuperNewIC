#ifndef STU_SHOWTALKDATA_H
#define STU_SHOWTALKDATA_H

#include <QWidget>

namespace Ui {
class Stu_ShowTalkData;
}

class Stu_ShowTalkData : public QWidget
{
    Q_OBJECT

public:
    explicit Stu_ShowTalkData(QWidget *parent = nullptr);
    ~Stu_ShowTalkData();

    void showDataWidget(QString);

private:
    Ui::Stu_ShowTalkData *ui;
};

#endif // STU_SHOWTALKDATA_H
