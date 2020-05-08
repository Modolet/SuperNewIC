#include "studentlistwidget.h"
#include "ui_studentlistwidget.h"

StudentListWidget::StudentListWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::StudentListWidget)
{
    ui->setupUi(this);
    this->setFixedSize(this->width(),this->height());//固定大小
}

StudentListWidget::~StudentListWidget()
{
    delete ui;
}
