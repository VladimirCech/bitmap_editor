#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "bucket.h"
#include "pentool.h"
#include "linetool.h"
#include "squaretool.h"
#include "circletool.h"

MainWindow::MainWindow(QWidget *parent) :
        QMainWindow(parent),
        ui(new Ui::MainWindow),
        image(800, 600, QImage::Format_ARGB32) {
    ui->setupUi(this);
    image.fill(Qt::white);

    penTool = new PenTool(this);
    lineTool = new LineTool(this);
    squareTool = new SquareTool(this);
    circleTool = new CircleTool(this);
    currentTool = penTool;

    lineWidth = ui->lineWidthSpinBox->value();

    tools = new QActionGroup(this);
    tools->addAction(ui->actionPen);
    tools->addAction(ui->actionBrush);
    tools->addAction(ui->actionCircle);
    tools->addAction(ui->actionSquare);
    tools->addAction(ui->actionLine);
    tools->addAction(ui->actionBucket);

    currentColor = Qt::black;

    connect(ui->lineWidthSpinBox, SIGNAL(valueChanged(int)), this, SLOT(onLineWidthChanged(int)));
    connect(ui->actionSave, SIGNAL(changed()), this, SLOT(on_actionSave_triggered()));
    connect(ui->actionOpen, SIGNAL(changed()), this, SLOT(on_actionOpen_triggered()));
    connect(ui->actionPrint, SIGNAL(changed()), this, SLOT(on_actionPrint_triggered()));
    connect(ui->actionPen, SIGNAL(triggered()), this, SLOT(on_actionPen_triggered()));
    connect(ui->actionLine, SIGNAL(triggered()), this, SLOT(on_actionLine_triggered()));
    connect(ui->actionSquare, SIGNAL(triggered()), this, SLOT(on_actionSquare_triggered()));
    connect(ui->actionCircle, SIGNAL(triggered()), this, SLOT(on_actionCircle_triggered()));

}

MainWindow::~MainWindow() {
    delete ui;
}

QImage *MainWindow::getImage() {
    return &image;
}

void MainWindow::paintEvent(QPaintEvent *event) {
    QPainter painter(this);
    painter.drawImage(0, 0, image);
    currentTool->setPen();
    painter.setPen(currentTool->getPen());

    QMainWindow::paintEvent(event);

    if (currentTool->isDrawing && ui->actionSquare->isChecked()) {
        QRect rect(currentTool->getStartPoint(), currentTool->getLastPoint());
        painter.drawRect(rect);
    } else if (currentTool->isDrawing && ui->actionCircle->isChecked()) {
        QRect rect(currentTool->getStartPoint(), currentTool->getLastPoint());
        painter.drawEllipse(rect);
    } else if (currentTool->isDrawing && ui->actionLine->isChecked()) {
        painter.drawLine(currentTool->getStartPoint(), currentTool->getLastPoint());
    }
}

void MainWindow::mousePressEvent(QMouseEvent *event) {
    if (currentTool) {
        if (ui->actionBucket->isChecked()) {
            Bucket::floodFill(image, event->pos(), image.pixelColor(event->pos()), currentColor);
        } else { currentTool->startDrawing(event->pos()); }
    }
    update();
}

void MainWindow::mouseMoveEvent(QMouseEvent *event) {
    if (currentTool) {
        currentTool->draw(event->pos());
    }
    update();
}

void MainWindow::mouseReleaseEvent(QMouseEvent *event) {
    if (currentTool) {
        currentTool->stopDrawing(event->pos());
    }
    update();
}

void MainWindow::onLineWidthChanged(int value) {
    lineWidth = value;
}


void MainWindow::on_setColorButton_clicked() {
    QColor color = QColorDialog::getColor(Qt::white, this, "Choose Drawing Color");
    if (color.isValid()) {
        currentColor = color;
        // Update the button's background or icon to reflect the chosen color.
        ui->setColorButton->setStyleSheet(QString("background-color: %1").arg(color.name()));
    }
}

void MainWindow::on_actionSave_triggered() {
    saveImage(image);
}

void MainWindow::on_actionOpen_triggered() {
    openImage();
}

void MainWindow::on_actionPrint_triggered() {
    printImage();
}

void MainWindow::on_actionPen_triggered() {
    currentTool = penTool;
}

void MainWindow::on_actionLine_triggered() {
    currentTool = lineTool;
}

void MainWindow::on_actionSquare_triggered() {
    currentTool = squareTool;
}

void MainWindow::on_actionCircle_triggered() {
    currentTool = circleTool;
}

void MainWindow::saveImage(const QImage &saveImage) {
    filePath = QFileDialog::getSaveFileName(nullptr, "Save Image", "",
                                            "PNG (*.png);;JPEG (*.jpeg *.jpg);;BMP (*.bmp);;All Files (*)");

    if (filePath.isEmpty()) {
        return;
    }

    QImageWriter writer(filePath);

    if (filePath.endsWith(".jpg") || filePath.endsWith(".jpeg")) {
        writer.setQuality(90); // Set quality between 0 (worst) to 100 (best)
    }

    if (!writer.write(saveImage)) {
        QMessageBox::critical(nullptr, "Error", "Failed to save the image: " + writer.errorString());
        return;
    }

    QMessageBox::information(nullptr, "Success", "Image saved successfully!");
}

void MainWindow::openImage() {
    // Show file open dialog
    QString fileName = QFileDialog::getOpenFileName(this,
                                                    tr("Open Image"),
                                                    QDir::homePath(),
                                                    tr("Images (*.png *.jpg *.bmp);;All Files (*)"));

    if (!fileName.isEmpty()) {
        QImage newImage;
        if (newImage.load(fileName)) {

            if (newImage.height() > window()->height() && newImage.width() > window()->width()) {
                QSize mainWindowSize = window()->size();
                QImage scaledImage = newImage.scaled(mainWindowSize, Qt::KeepAspectRatio, Qt::SmoothTransformation);
                image = scaledImage;
            } else {
                image = newImage;
            }
            window()->update();
        } else {
            // Error handling
            QMessageBox::warning(this, tr("Open Image"), tr("The image file could not be loaded."));
        }
    }
}

void MainWindow::printImage() {
    QPrinter printer(QPrinter::HighResolution);
    QPrintDialog printDialog(&printer, this);

    if (printDialog.exec() == QDialog::Accepted) {
        QPainter painter(&printer);
        QRect rect = painter.viewport();

        QSize size = image.size();
        size.scale(rect.size(), Qt::KeepAspectRatio);

        painter.setViewport(rect.x(), rect.y(), size.width(), size.height());
        painter.setWindow(image.rect());

        painter.drawImage(0, 0, image);
    }
}



