#ifndef BITMAP_EDITOR_PENTOOL_H
#define BITMAP_EDITOR_PENTOOL_H

#include "drawingtool.h"

class PenTool : public DrawingTool {
public:
    explicit PenTool(MainWindow *window);

    void startDrawing(QPoint startPoint) override;
    void draw(QPoint currentPoint) override;
    void stopDrawing(QPoint endPoint) override;
};


#endif //BITMAP_EDITOR_PENTOOL_H
