#include <iostream>
#include "pencil.h"
#include "mainwindow.h"

Pencil::Pencil(MainWindow *window) :
        window(window),
        isDrawing(false) {}

void Pencil::setPen() {
    pen.setColor(window->currentColor);
    pen.setWidth(window->lineWidth);
    pen.setJoinStyle(Qt::RoundJoin);
    pen.setCapStyle(Qt::RoundCap);
}

// logic for drawing lines

void Pencil::startDrawing(const QPoint &point) {
    isDrawing = true;
    lastPoint = point;
    setPen();

    QPainter painter(window->getImage());
    painter.setPen(pen);
    painter.drawPoint(lastPoint);
}

void Pencil::draw(const QPoint &point) {
    if (!isDrawing) return;

    QPainter painter(window->getImage());
    painter.setPen(pen);
    painter.drawLine(lastPoint, point);
    lastPoint = point;
}

void Pencil::stopDraw() {
    isDrawing = false;
}

// Logic for square drawing

void Pencil::startDrawSquare(const QPoint &point) {
    isDrawing = true;
    startPoint = point;
    lastPoint = point;
}

void Pencil::drawSquare(const QPoint &point) {
    if (!isDrawing) return;
    lastPoint = point;
}

void Pencil::stopDrawSquare(const QPoint &point) {
    if (!isDrawing) return;
    isDrawing = false;
    lastPoint = point;
    setPen();

    QPainter painter(window->getImage());
    painter.setPen(pen);
    QRect rect(startPoint, lastPoint);
    painter.drawRect(rect);
}

// Logic for circle drawing

void Pencil::startDrawCircle(const QPoint &point) {
    isDrawing = true;
    startPoint = point;
    lastPoint = point;
}

void Pencil::drawCircle(const QPoint &point) {
    if (!isDrawing) return;
    lastPoint = point;
}

void Pencil::stopDrawCircle(const QPoint &point) {
    if (!isDrawing) return;
    isDrawing = false;
    lastPoint = point;

    setPen();
    QPainter painter(window->getImage());
    painter.setPen(pen);
    QRect rect(startPoint, lastPoint);
    painter.drawEllipse(rect);

}

// Logic for drawing straight line

void Pencil::startDrawLine(const QPoint &point) {
    isDrawing = true;
    startPoint = point;
    lastPoint = point;
}

void Pencil::drawLine(const QPoint &point) {
    if (!isDrawing) return;
    lastPoint = point;

}

void Pencil::stopDrawLine(const QPoint &point) {
    if (!isDrawing) return;
    isDrawing = false;
    lastPoint = point;

    setPen();
    QPainter painter(window->getImage());
    painter.setPen(pen);
    painter.drawLine(startPoint, lastPoint);
}

void Pencil::floodFill(QImage &image, QPoint point, QColor oldColor, QColor newColor) {
    // Check if the start point has the old color
    if (colorsAreClose(oldColor, newColor)){
        return;
    }

    QStack<QPoint> stack;
    stack.push(point);

    while (!stack.isEmpty()) {
        point = stack.pop();

        // Check the current point's color
        if (image.pixelColor(point) != oldColor) {
            continue;
        }

        // Set the new color to the current point
        image.setPixelColor(point, newColor);

        // Push neighboring points to the stack
        if (point.x() > 0) stack.push(point + QPoint(-1, 0));
        if (point.x() < image.width() - 1) stack.push(point + QPoint(1, 0));
        if (point.y() > 0) stack.push(point + QPoint(0, -1));
        if (point.y() < image.height() - 1) stack.push(point + QPoint(0, 1));

//        window->update();
//        qApp->processEvents();
    }
}

QPoint Pencil::getStartPoint() {
    return startPoint;
}

QPoint Pencil::getLastPoint() {
    return lastPoint;
}

QPen Pencil::getPen() {
    return pen;
}

bool Pencil::colorsAreClose(QColor a, QColor b, int tolerance) {
    int dr = a.red() - b.red();
    int dg = a.green() - b.green();
    int db = a.blue() - b.blue();
    int distanceSquared = dr * dr + dg * dg + db * db;
    return distanceSquared <= (tolerance * tolerance);
}
