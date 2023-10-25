#include "pentool.h"

void PenTool::startDrawing(QPoint startPoint) {
    isDrawing = true;
    lastPoint = startPoint;
    setPen();

    QPainter painter(window->getImage());
    painter.setPen(pen);
    painter.drawPoint(lastPoint);
}

void PenTool::draw(QPoint currentPoint) {
    if (!isDrawing) return;

    QPainter painter(window->getImage());
    painter.setPen(pen);
    painter.drawLine(lastPoint, currentPoint);
    lastPoint = currentPoint;
}

void PenTool::stopDrawing(QPoint endPoint) {
    isDrawing = false;
}