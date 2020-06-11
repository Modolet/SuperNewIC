#include "mainwindow.h"

#include <QDebug>
#include <QList>
#include <QImage>
#include <QPixmap>
#include <QSize>
#include <QByteArray>
#include <QBuffer>
#include <QImageReader>
#include <QFileDialog>

#include "ui_mainwindow.h"
MainWindow::MainWindow(QWidget* parent, network* net)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
    this->setFixedSize(this->width(), this->height());  //固定窗口大小
    this->net = net;
    icon = new QIcon(":/Icon/2.jpeg");
    //文件相关
    theme = new QFile;
    theme->setFileName("theme");
    //获取信息
    getInfo();
    //初始化菜单
    initMenu();


}

MainWindow::~MainWindow() { delete ui; }

void MainWindow::getInfo()
{
    //获取教师信息
    info sc_info = net->getInfo();
    ui->label_name->setText(sc_info.name);
    ui->label_sign->setText(sc_info.sign);
    if(sc_info.image.size() == 0)
    {
        ui->toolButton_icon->setIcon(*icon);
        ui->toolButton_icon->setIconSize(QSize(50,50));
    }
    else
    {
        //将QByteArray转为QImageReader
        QBuffer buffer(&sc_info.image);
        buffer.open(QIODevice::ReadOnly);
        QImageReader reader(&buffer,sc_info.format.toStdString().c_str());
        qDebug() << sc_info.format;
        QImage img = reader.read();
        qDebug() << buffer.size();
        //设置头像和大小
        ui->toolButton_icon->setIcon(QPixmap::fromImage(img));
        ui->toolButton_icon->setIconSize(this->size());
    }

    //获取小组信息
    QList<QString> groupList = net->getGroupList();
    QList<QString>::const_iterator i;
    for(i=groupList.begin();i!=groupList.end();i++)
    {

        ui->studentList->addGroup(*i);
    }
    //获取学生列表
    QList<studentInfo> stuInfoList = net->GetStudentList();
    QList<studentInfo>::const_iterator i_stu;
    for(i_stu = stuInfoList.begin();i_stu != stuInfoList.end();i_stu++)
    {
        ui->studentList->addStudent(*i_stu);
    }

    //获取主题状态
    int themeid;
    theme->open(QIODevice::ReadWrite);
    theme->read((char*)&themeid,sizeof(int));
    setqss(themeid);
    theme->close();
}

void MainWindow::setqss(int id)
{
    QString qss;
    QFile qssFile;
    if(id != 3)
        qssFile.setFileName(QString(":/qss/style0%1.qss").arg(id));
    else
        qssFile.setFileName(":/qss/list.qss");
    qssFile.open(QFile::ReadOnly);

    if (qssFile.isOpen())
    {
      qss = QLatin1String(qssFile.readAll());
      qApp->setStyleSheet(qss);
      qssFile.close();
    }
    //保存选择的主题
    theme->open(QIODevice::ReadWrite);
    theme->write((char*)&id,sizeof(int));
    theme->close();
}

void MainWindow::on_toolButton_icon_clicked()
{

}

void MainWindow::slot_style_1()
{
    setqss(1);
    QMessageBox::information(this,"提示","更换主题成功！");
}

void MainWindow::slot_style_2()
{
    setqss(2);
    QMessageBox::information(this,"提示","更换主题成功！");
}

void MainWindow::slot_style_3()
{
    setqss(3);
    QMessageBox::information(this,"提示","更换主题成功！");
}

void MainWindow::slot_viewAll()
{
    AllStuScore* AST = new AllStuScore(nullptr,net);
    AST->show();
}

void MainWindow::slot_about()
{

}

void MainWindow::slot_changeIcon()
{
    QFile* imgFile = new QFile(QFileDialog::getOpenFileName(nullptr,"请选择头像文件",nullptr,"图像文件（*.BMP *.GIF *.JPG *.JPEG *.PNG *.PBN *.PGM *.PPM *.XBM *.XPM"));
    if(imgFile->fileName() == NULL)
        return;
    else
    {
        Sleep(500);
        ChangeUserIcon* ci = new ChangeUserIcon(this,imgFile);
        connect(ci,SIGNAL(signalCompleteCature(QPixmap,QString)),this,SLOT(slot_updateIcon(QPixmap,QString)));
        ci->show();

    }
}

void MainWindow::slot_updateIcon(QPixmap catureImage, QString format)
{
    if(catureImage.size().width() <= 50)
    {
        QMessageBox::warning(this,"错误","您选择的图片过小！请选择分辨率大于50x50的图片！");
        return;
    }
    //将图片转为QByteArray
    QBuffer buffer;
    QByteArray* pixArray = new QByteArray;
    buffer.open(QIODevice::ReadWrite);
    catureImage.save(&buffer,format.toStdString().c_str());
    pixArray->append(buffer.data());
    if(net->updateIcon(ex_id,pixArray,format))
    {
        QMessageBox::information(this,"提示","修改成功！");
        this->ui->toolButton_icon->setIcon(QIcon(catureImage));
    }
}

void MainWindow::slot_changeSign()
{
    le_sign = new QLineEdit(this);
    connect(le_sign,SIGNAL(editingFinished()),this,SLOT(slot_updateSign()));
    le_sign->setGeometry(65,35,165,20);
    le_sign->show();
    le_sign->setText(ui->label_sign->text());
    le_sign->selectAll();
    le_sign->setFocus();
}

void MainWindow::slot_updateSign()
{
    QString sign = le_sign->text();
    le_sign->hide();
    if(net->updateSign(sign))
    {
        this->ui->label_sign->setText(sign);
    }
    else
    {
        QMessageBox::warning(this,"错误","数据传输出现错误！请检查网络连接后重试！");
    }
}

void MainWindow::initMenu()
{
    settingMenu = new QMenu();
    iconMenu = new QMenu();
    t_style = new QMenu("改变主题");
    QAction* style_1 = new QAction("样式一",this);
    QAction* style_2 = new QAction("样式二",this);
    QAction* style_3 = new QAction("默认",this);

    QAction* viewAll = new QAction("查看所有学生成绩",this);
    QAction* about = new QAction("关于",this);
    QAction* changeIcon = new QAction("修改头像",this);
    QAction* changeSign = new QAction("修改签名",this);
    t_style->addAction(style_1);
    t_style->addAction(style_2);
    t_style->addAction(style_3);

    settingMenu->addAction(viewAll);
    settingMenu->addMenu(t_style);
    settingMenu->addAction(about);

    iconMenu->addAction(changeIcon);
    iconMenu->addAction(changeSign);

    //添加到按钮
    ui->pushButton_menu->setMenu(settingMenu);
    ui->toolButton_icon->setMenu(iconMenu);
    ui->toolButton_icon->setPopupMode(QToolButton::InstantPopup);

    //隐藏三角
    ui->toolButton_icon->setStyleSheet("QToolButton::menu-indicator{image:none;}");
    //传值
    ui->studentList->setNetwork(net);

    //信号和槽
    connect(style_1,SIGNAL(triggered()),this,SLOT(slot_style_1()));
    connect(style_2,SIGNAL(triggered()),this,SLOT(slot_style_2()));
    connect(style_3,SIGNAL(triggered()),this,SLOT(slot_style_3()));
    connect(changeIcon,SIGNAL(triggered()),this,SLOT(slot_changeIcon()));
    connect(viewAll,SIGNAL(triggered()),this,SLOT(slot_viewAll()));
    connect(changeSign,SIGNAL(triggered()),this,SLOT(slot_changeSign()));
}
