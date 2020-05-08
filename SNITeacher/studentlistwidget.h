#ifndef STUDENTLISTWIDGET_H
#define STUDENTLISTWIDGET_H

#include <QWidget>

namespace Ui {
class StudentListWidget;
}

class StudentListWidget : public QWidget
{
    Q_OBJECT

public:
    explicit StudentListWidget(QWidget *parent = nullptr);
    ~StudentListWidget();

private:
    Ui::StudentListWidget *ui;
};

#endif // STUDENTLISTWIDGET_H
