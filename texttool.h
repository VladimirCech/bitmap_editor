#ifndef BITMAP_EDITOR_TEXTTOOL_H
#define BITMAP_EDITOR_TEXTTOOL_H

#include "drawingtool.h"

class TextTool : public DrawingTool {
public:
    explicit TextTool(MainWindow *window);
    void setText(const QString& text);
    void startDrawing(QPoint startPoint) override;
    void draw(QPoint currentPoint) override;
    void stopDrawing(QPoint endPoint) override;

private:
    QString textToDraw;
    QPoint textStartPoint;
    QFont textFont;
};


#endif //BITMAP_EDITOR_TEXTTOOL_H
