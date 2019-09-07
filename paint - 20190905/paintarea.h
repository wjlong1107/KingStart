#ifndef PAINTAREA_H
#define PAINTAREA_H

#include <QWidget>
#include<QMouseEvent>
#include<QPoint>

class paintArea : public QWidget
{
    Q_OBJECT
public:
    paintArea();
protected:
    void paintEvent(QPaintEvent *);
    void mousePressEvent(QMouseEvent *);
    void mouseMoveEvent(QMouseEvent *);
    void mouseReleaseEvent(QMouseEvent *);
    void paint(QImage &);
private:
    QImage image;   //QImage 类对象，用于在其上绘图
    QRgb backColor; //QRgb颜色对象，存储image的背景色
    QPoint lastPoint,endPoint;//定义两个坐标对象存放鼠标指针的前后两个坐标

signals:

public slots:
};

#endif // PAINTAREA_H
