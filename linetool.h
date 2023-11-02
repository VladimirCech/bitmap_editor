#ifndef BITMAP_EDITOR_LINETOOL_H
#define BITMAP_EDITOR_LINETOOL_H

#include "drawingtool.h"

class LineTool : public DrawingTool {
public:
    explicit LineTool(MainWindow *window);

    void startDrawing(QPoint startPoint) override;
    void draw(QPoint currentPoint) override;
    void stopDrawing(QPoint endPoint) override;
};


#endif //BITMAP_EDITOR_LINETOOL_H
