#include "stu_showtalkdata.h"
#include "ui_stu_showtalkdata.h"

Stu_ShowTalkData::Stu_ShowTalkData(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Stu_ShowTalkData)
{
    ui->setupUi(this);
    this->setFixedSize(274, 700);
}

Stu_ShowTalkData::~Stu_ShowTalkData()
{
    delete ui;
}

void Stu_ShowTalkData::showDataWidget(QString str)
{
    ui->plainTextEdit->setPlainText(str);
}
