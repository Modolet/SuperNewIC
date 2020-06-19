#include "allstuscore.h"
#include "ui_allstuscore.h"

AllStuScore::AllStuScore(QWidget *parent,Network* net) :
    QWidget(parent),
    ui(new Ui::AllStuScore)
{
    ui->setupUi(this);\
    this->setWindowFlag(Qt::Window);
    this->net = net;
    init();
}

AllStuScore::~AllStuScore()
{
    delete ui;
}

void AllStuScore::resizeEvent(QResizeEvent *event)
{
    this->ui->tableView->resize(geometry().width(),geometry().height());
    return QWidget::resizeEvent(event);
}

void AllStuScore::init()
{
    this->resize(315,900);
    this->setFixedWidth(315);
    this->setWindowTitle("成绩列表");
    QSqlQuery sq = net->getSQ();
    model = new QSqlQueryModel;
    model = net->setDatasModel();
    model->setQuery("select id,name,score from datas where is_teacher is null");
    model->setHeaderData(0,Qt::Horizontal,"学号");
    model->setHeaderData(1,Qt::Horizontal,"姓名");
//    model->setHeaderData(2,Qt::Horizontal,"性别");
//    model->setHeaderData(3,Qt::Horizontal,"班级");
    model->setHeaderData(4,Qt::Horizontal,"成绩");

    this->ui->tableView->setModel(model);
    this->ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents );
    qDebug() << geometry();
    //this->ui->tableView->setGeometry(0,0,315,900);

    this->ui->tableView->resize(geometry().width(),geometry().height());
    //horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);//所有列都扩展自适应宽度，填充充满整个屏幕宽度
    //horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents );//根据列内容来定列宽
    //horizontalHeader()->setSectionResizeMode(0, QHeaderView::Fixed);//对第0列单独设置固定宽度

}
