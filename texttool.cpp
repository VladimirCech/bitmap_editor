#include "texttool.h"
#include <QPainter>

TextTool::TextTool(MainWindow *window) : DrawingTool(window) {
}

void TextTool::setText(const QString& text) {
    textToDraw = text;
}

void TextTool::startDrawing(QPoint startPoint) {
    textStartPoint = startPoint;
    isDrawing = true;
}

void TextTool::draw(QPoint currentPoint) {
}

void TextTool::stopDrawing(QPoint endPoint) {
    if (!isDrawing) return;
    isDrawing = false;

    textFont.setPointSize(window->lineWidth);
    QPainter painter(window->getImage());
    painter.setFont(textFont);
    painter.setPen(pen);
    painter.drawText(textStartPoint, textToDraw);
}
