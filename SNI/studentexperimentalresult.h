#ifndef STUDENTEXPERIMENTALRESULT_H
#define STUDENTEXPERIMENTALRESULT_H

#if _MSC_VER >= 1600	// MSVC2015 > 1899,	MSVC_VER = 14.0
#pragma execution_character_set("utf-8")
#endif

#include <QWidget>
#include <QSqlTableModel>
#include <QString>
#include "const.h"
#include "network.h"

namespace Ui {
class StudentExperimentalResult;
}

class StudentExperimentalResult : public QWidget
{
    Q_OBJECT

public:
    explicit StudentExperimentalResult(QWidget *parent = nullptr,Network* net = nullptr,int id = 0);
    ~StudentExperimentalResult();

private:
    QSqlDatabase db;
    Network* net;
    int id;
    info sc_stuInfo;
    Ui::StudentExperimentalResult *ui;
    QSqlTableModel* model;
    void resizeEvent(QResizeEvent *event);
    void setInfo();
};

#endif // STUDENTEXPERIMENTALRESULT_H
