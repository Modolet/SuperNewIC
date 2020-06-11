#ifndef CHANGEUSERICON_H
#define CHANGEUSERICON_H

#include <QWidget>
#include <QFile>
#include <QPixmap>
#include <QPainter>
#include <QMouseEvent>
#include <QColor>
#include <QRect>
#include <QDebug>
#include <QString>
#include <QFileInfo>
enum CaptureState{
    initCapture = 0,
    beginCaptureImage,
    finishCaptureImage,
    beginMoveCaptureArea,
    finishMoveCaptureArea,
    beginMoveStretchRect,
    finishMoveStretchRect
}; //进行截取的状态;

enum StretchRectState{
    NotSelect = 0,
    TopLeftRect,
    TopRightRect,
    BottomLeftRect,
    BottomRightRect,
    LeftCenterRect,
    TopCenterRect,
    RightCenterRect,
    BottomCenterRect
};// 当前鼠标所在顶点状态;

namespace Ui {
class ChangeUserIcon;
}

class ChangeUserIcon : public QWidget
{
    Q_OBJECT

public:
    explicit ChangeUserIcon(QWidget *parent = nullptr,QFile* imgFile = nullptr);
    ~ChangeUserIcon();

signals:
    void signalCompleteCature(QPixmap catureImage,QString format);

private:
    Ui::ChangeUserIcon *ui;

    QFile* imgFile;
    QPixmap m_loadPixmap, m_capturePixmap;
    int m_screenwidth;
    int m_screenheight;
    //保存确定选区的坐标点;
    QPoint m_beginPoint, m_endPoint,m_beginMovePoint,m_endMovePoint,currentPoint;
    //保存当前选取状态
    CaptureState m_currentCaptureState;
    QPainter m_painter;
    // 当前选择区域矩形;
    QRect m_currentSelectRect;
    // 选中矩形8个顶点小矩形;
    QRect m_topLeftRect, m_topRightRect, m_bottomLeftRect, m_bottomRightRect;
    QRect m_leftCenterRect, m_topCenterRect, m_rightCenterRect, m_bottomCenterRect;
    //当前鼠标所在顶点状态
    StretchRectState m_stretchRectState;
    void initWindow();
    void loadPixmap();
    QRect getRect(const QPoint &beginPoint,const QPoint &endPoint);
    QRect getMoveRect();
    bool isPressPointInSelectRect(QPoint mousePressPoint);
    QRect getSelectRect();
    void drawCaptureImage();
    QPoint getMovePoint();
    void mousePressEvent(QMouseEvent* event);
    void mouseMoveEvent(QMouseEvent* event);
    void mouseReleaseEvent(QMouseEvent* event);
    void paintEvent(QPaintEvent *event);
    void keyPressEvent(QKeyEvent *event);

    void initStretchRect();
    QRect getStretchRect();
    StretchRectState getStrethRectState(QPoint point);
    void setStretchCursorStyle(StretchRectState stretchRectState);
    void drawStretchRect();
    bool isPressPointInWindow(QPoint mousePressPoint);
    void drawSelectRectInfo();
    void drawEndPointImage();

};

#endif // CHANGEUSERICON_H
