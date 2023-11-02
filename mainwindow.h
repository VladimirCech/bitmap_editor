#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QImage>
#include <QPainter>
#include <QMouseEvent>
#include <QColorDialog>
#include <QFileDialog>
#include <QImageWriter>
#include <QMessageBox>
#include <QString>
#include <QPrinter>
#include <QPrintDialog>

#include "bucket.h"

namespace Ui {
    class MainWindow;
}

class DrawingTool;

class PenTool;

class LineTool;

class SquareTool;

class CircleTool;

class MainWindow : public QMainWindow {
Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);

    ~MainWindow();

    QImage *getImage();

    int lineWidth;
    QColor currentColor;
    QActionGroup *tools;
protected:

    void paintEvent(QPaintEvent *event) override;

    void mouseMoveEvent(QMouseEvent *event) override;

    void mousePressEvent(QMouseEvent *event) override;

    void mouseReleaseEvent(QMouseEvent *event) override;

    void saveImage(const QImage &image);

    void printImage();

    void openImage();

private:

    Ui::MainWindow *ui;
    QImage image;
    QString filePath;
    PenTool *penTool;
    LineTool *lineTool;
    SquareTool *squareTool;
    CircleTool *circleTool;
    DrawingTool *currentTool;

private slots:

    void onLineWidthChanged(int value);

    void on_setColorButton_clicked();

    void on_actionSave_triggered();

    void on_actionOpen_triggered();

    void on_actionPrint_triggered();

    void on_actionPen_triggered();

    void on_actionLine_triggered();

    void on_actionSquare_triggered();

    void on_actionCircle_triggered();
};

#endif // MAINWINDOW_H
