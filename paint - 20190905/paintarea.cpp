#include "paintarea.h"
#include<QPainter>

paintArea::paintArea()
{
    image = QImage(400,300,QImage::Format_RGB32);   //画布的初始化大小设为400*300，颜色使用32位颜色
    backColor = qRgb(255,255,255);                  //画布初始化背景色使用白色
    image.fill(backColor);
}
void paintArea::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    painter.drawImage(0,0,image);
}

void paintArea::mousePressEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton)
    {
        lastPoint = event->pos();
    }
}

void paintArea::mouseMoveEvent(QMouseEvent *event)
{
    if(event->buttons()&Qt::LeftButton)
    {
        endPoint = event->pos();
        paint(image);
    }
}

void paintArea::mouseReleaseEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton)
    {
        endPoint = event->pos();
        paint(image);
    }
}

void paintArea::paint(QImage &theImage)
{
    QPainter pp(&theImage);             //在theImage上绘图
    pp.drawLine(lastPoint,endPoint);    //由起始坐标和终止坐标绘制直线
    lastPoint = endPoint;               //让终止坐标变为其实坐标
    update();                           //进行更新界面显示,可引起窗口重绘事件,重绘窗口
}
