#ifndef BITMAP_EDITOR_CIRCLETOOL_H
#define BITMAP_EDITOR_CIRCLETOOL_H

#include "drawingtool.h"

class CircleTool : public DrawingTool {
public:
    explicit CircleTool(MainWindow *window);

    void startDrawing(QPoint startPoint) override;
    void draw(QPoint currentPoint) override;
    void stopDrawing(QPoint endPoint) override;
};


#endif //BITMAP_EDITOR_CIRCLETOOL_H
