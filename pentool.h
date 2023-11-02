#ifndef BITMAP_EDITOR_PENTOOL_H
#define BITMAP_EDITOR_PENTOOL_H

#include "drawingtool.h"

class PenTool : public DrawingTool {
public:
    explicit PenTool(MainWindow *window);

    void startDrawing(QPoint startPoint);
    void draw(QPoint currentPoint);
    void stopDrawing(QPoint endPoint);
};


#endif //BITMAP_EDITOR_PENTOOL_H
