#ifndef STUDENTEXPERIMENTALRESULT_H
#define STUDENTEXPERIMENTALRESULT_H

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
    explicit StudentExperimentalResult(QWidget *parent = nullptr,network* net = nullptr,int id = 0);
    ~StudentExperimentalResult();

private:
    network* net;
    int id;
    info sc_stuInfo;
    Ui::StudentExperimentalResult *ui;
    QSqlTableModel* model;
    void resizeEvent(QResizeEvent *event);
    void setInfo();
};

#endif // STUDENTEXPERIMENTALRESULT_H
