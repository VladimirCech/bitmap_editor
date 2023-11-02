#ifndef DRAWINGTOOL_H
#define DRAWINGTOOL_H

#include "mainwindow.h"
#include <QPoint>

class MainWindow;

class DrawingTool {
public:
    explicit DrawingTool(MainWindow *window);
    virtual void startDrawing(QPoint startPoint) = 0;
    virtual void draw(QPoint currentPoint) = 0;
    virtual void stopDrawing(QPoint endPoint) = 0;
    virtual ~DrawingTool() = default;
    QPoint getStartPoint();
    QPoint getLastPoint();
    void setPen();
    QPen getPen();
    bool isDrawing;

protected:
    MainWindow* window;
    QPen pen;
    QPoint lastPoint;
    QPoint startPoint;

};

#endif // DRAWINGTOOL_H
