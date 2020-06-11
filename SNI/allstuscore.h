#ifndef ALLSTUSCORE_H
#define ALLSTUSCORE_H

#include <QWidget>
#include <QSqlQueryModel>
#include "network.h"

namespace Ui {
class AllStuScore;
}

class AllStuScore : public QWidget
{
    Q_OBJECT

public:
    explicit AllStuScore(QWidget *parent = nullptr,network* net = nullptr);
    ~AllStuScore();

private:
    Ui::AllStuScore *ui;
    network* net;
    QSqlQueryModel* model;
    void resizeEvent(QResizeEvent *event);
    void init();
};

#endif // ALLSTUSCORE_H
