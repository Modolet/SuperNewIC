#include "studentexperimentalresult.h"
#include "ui_studentexperimentalresult.h"

StudentExperimentalResult::StudentExperimentalResult(QWidget *parent,Network* net,int id) :
    QWidget(parent),
    ui(new Ui::StudentExperimentalResult)
{
    ui->setupUi(this);
    this->net = net;
    this->id = id;
    this->setWindowFlag(Qt::Window);
    model = new QSqlTableModel;
    setInfo();
    //this->ui->tableView->setColumnWidth(0,200);
    this->ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
    this->resize(480,600);
    //this->setFixedWidth(150);
}

StudentExperimentalResult::~StudentExperimentalResult()
{
    delete ui;
}

void StudentExperimentalResult::resizeEvent(QResizeEvent *event)
{
    this->ui->tableView->resize(geometry().width(),geometry().height());
    return QWidget::resizeEvent(event);
}

void StudentExperimentalResult::setInfo()
{
    db = net->getDB();
    model = new QSqlTableModel(this,db);
    model->setTable(QString::number(id));     // 连接到该学生使用的表
    model->removeColumns(4, 7);
    model->select();                             // 显示tableModel数据
    ui->tableView->setModel(model);
    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableView->horizontalHeader()->setStretchLastSection(false);
    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);//使其不可编辑
    sc_stuInfo = net->getInfo(id);
    this->setWindowTitle(QString("%1的实验数据，成绩：%2").arg(sc_stuInfo.name).arg(sc_stuInfo.score));
}
