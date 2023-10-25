#ifndef DRAWINGTOOL_H
#define DRAWINGTOOL_H

#include "mainwindow.h"
#include <QPoint>

class MainWindow;

class DrawingTool {
public:
    DrawingTool(MainWindow *window);
    virtual void startDrawing(QPoint startPoint) = 0;
    virtual void draw(QPoint currentPoint) = 0;
    virtual void stopDrawing(QPoint endPoint) = 0;
    virtual ~DrawingTool() = default;

    void setPen();

protected:
    MainWindow* window;
    QPen pen;
    QPoint lastPoint;
    QPoint startPoint;
    bool isDrawing;

};

#endif // DRAWINGTOOL_H
