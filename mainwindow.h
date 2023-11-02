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

#include "pencil.h"

namespace Ui {
    class MainWindow;
}

class DrawingTool;
class PenTool;

class MainWindow : public QMainWindow {
Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    QImage* getImage();
    int lineWidth;
    QColor currentColor;
    QActionGroup *tools;
protected:

    void paintEvent(QPaintEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;
    void saveImage(const QImage& image);
    void printImage();
    void openImage();
private:

    Ui::MainWindow *ui;
    QImage image;
    Pencil *pencil;
    QString filePath;
    PenTool* penTool;
    DrawingTool* currentTool;

private slots:
    void onLineWidthChanged(int value);
    void on_setColorButton_clicked();
    void on_actionSave_triggered();
    void on_actionOpen_triggered();
    void on_actionPrint_triggered();
    void on_actionPen_triggered();
};

#endif // MAINWINDOW_H
