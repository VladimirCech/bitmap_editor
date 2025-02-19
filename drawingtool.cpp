#include "drawingtool.h"
#include "mainwindow.h"

DrawingTool::DrawingTool(MainWindow *window) : window(window) {
}

void DrawingTool::setPen(){
    pen.setColor(window->currentColor);
    pen.setWidth(window->lineWidth);
    pen.setJoinStyle(Qt::RoundJoin);
    pen.setCapStyle(Qt::RoundCap);
}

QPen DrawingTool::getPen() {
    return pen;
}

QPoint DrawingTool::getStartPoint() {
    return startPoint;
}

QPoint DrawingTool::getLastPoint() {
    return lastPoint;
}
