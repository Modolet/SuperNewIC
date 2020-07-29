#ifndef ALLSTUSCORE_H
#define ALLSTUSCORE_H

#if _MSC_VER >= 1600	// MSVC2015 > 1899,	MSVC_VER = 14.0
#pragma execution_character_set("utf-8")
#endif

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
    explicit AllStuScore(QWidget *parent = nullptr,Network* net = nullptr);
    ~AllStuScore();

private:
    Ui::AllStuScore *ui;
    Network* net;
    QSqlQueryModel* model;
    void resizeEvent(QResizeEvent *event);
    void init();
};

#endif // ALLSTUSCORE_H
