#include <iostream>
#include "bucket.h"

void Bucket::floodFill(QImage &image, QPoint point, QColor oldColor, QColor newColor) {
    // Check if the start point has the old color
    if (colorsAreClose(oldColor, newColor)){
        return;
    }

    if (point.x() > image.width() || point.y() > image.width()){
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

bool Bucket::colorsAreClose(QColor a, QColor b, int tolerance) {
    int dr = a.red() - b.red();
    int dg = a.green() - b.green();
    int db = a.blue() - b.blue();
    int distanceSquared = dr * dr + dg * dg + db * db;
    return distanceSquared <= (tolerance * tolerance);
}
