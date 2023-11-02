#include "squaretool.h"

SquareTool::SquareTool(MainWindow *window) : DrawingTool(window) {

}

void SquareTool::startDrawing(const QPoint point) {
    isDrawing = true;
    startPoint = point;
    lastPoint = point;
}

void SquareTool::draw(const QPoint currentPoint) {
    if (!isDrawing) return;
    lastPoint = currentPoint;

}

void SquareTool::stopDrawing(const QPoint endPoint) {
    if (!isDrawing) return;
    isDrawing = false;
    lastPoint = endPoint;

    setPen();
    QPainter painter(window->getImage());
    painter.setPen(pen);
    QRect rect(startPoint, lastPoint);
    painter.drawRect(rect);
}

