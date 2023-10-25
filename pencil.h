#ifndef PENCIL_H
#define PENCIL_H

#include <QPoint>
#include <QPen>
#include <QPainter>
#include <QActionGroup>
#include <QPaintEvent>
#include <QStack>
#include <QApplication>

class MainWindow;

class Pencil {
public:
    Pencil(MainWindow *window);
    void startDrawing(const QPoint &point);
    void draw(const QPoint &point);
    void stopDraw();
    void setPen();
    void startDrawSquare(const QPoint &point);
    void drawSquare(const QPoint &point);
    void stopDrawSquare(const QPoint &point);
    void startDrawCircle(const QPoint &point);
    void drawCircle(const QPoint &point);
    void stopDrawCircle(const QPoint &point);
    void startDrawLine(const QPoint &point);
    void drawLine(const QPoint &point);
    void stopDrawLine(const QPoint &point);
    static void floodFill(QImage &image,QPoint point, QColor oldColor, QColor newColor);
    static bool colorsAreClose(QColor a, QColor b, int tolerance = 5);
    bool isDrawing;

    QPoint getStartPoint();
    QPoint getLastPoint();
    QPen getPen();

private:
    MainWindow *window;
    QPoint lastPoint;
    QPen pen;
    QPoint startPoint;
};

#endif // PENCIL_H
