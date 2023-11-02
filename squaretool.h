#ifndef BITMAP_EDITOR_SQUARETOOL_H
#define BITMAP_EDITOR_SQUARETOOL_H

#include "drawingtool.h"

class SquareTool : public DrawingTool {
public:
    explicit SquareTool(MainWindow *window);

    void startDrawing(QPoint startPoint) override;
    void draw(QPoint currentPoint) override;
    void stopDrawing(QPoint endPoint) override;
};



#endif //BITMAP_EDITOR_SQUARETOOL_H
