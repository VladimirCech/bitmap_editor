#ifndef PENCIL_H
#define PENCIL_H

#include <QPoint>
#include <QPen>
#include <QPainter>
#include <QStack>

class MainWindow;

class Bucket {
public:
    static void floodFill(QImage &image,QPoint point, QColor oldColor, QColor newColor);
    static bool colorsAreClose(QColor a, QColor b, int tolerance = 5);

private:
    MainWindow *window;
    QPen pen;
    QPoint startPoint;
};

#endif // PENCIL_H
