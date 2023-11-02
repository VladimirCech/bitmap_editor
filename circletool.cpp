#include "circletool.h"

CircleTool::CircleTool(MainWindow *window) : DrawingTool(window) {

}

void CircleTool::startDrawing(const QPoint point) {
    isDrawing = true;
    startPoint = point;
    lastPoint = point;
}

void CircleTool::draw(const QPoint point) {
    if (!isDrawing) return;
    lastPoint = point;
}

void CircleTool::stopDrawing(const QPoint point) {
    if (!isDrawing) return;
    isDrawing = false;
    lastPoint = point;

    setPen();
    QPainter painter(window->getImage());
    painter.setPen(pen);
    QRect rect(startPoint, lastPoint);
    painter.drawEllipse(rect);

}