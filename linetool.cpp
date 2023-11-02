#include "linetool.h"


LineTool::LineTool(MainWindow *window) : DrawingTool(window) {

}

void LineTool::startDrawing(const QPoint point) {
    isDrawing = true;
    startPoint = point;
    lastPoint = point;
}

void LineTool::draw(const QPoint currentPoint) {
    if (!isDrawing) return;
    lastPoint = currentPoint;

}

void LineTool::stopDrawing(const QPoint endPoint) {
    if (!isDrawing) return;
    isDrawing = false;
    lastPoint = endPoint;

    setPen();
    QPainter painter(window->getImage());
    painter.setPen(pen);
    painter.drawLine(startPoint, lastPoint);
}

