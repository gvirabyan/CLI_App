#ifndef WINDOW_H
#define WINDOW_H

#include <vector>
#include "Widget.h"

class Window : public Widget {
private:
    std::vector<Widget*> children;
    std::vector<std::vector<Widget*>> grid;
    int m_rowCount;
    int m_colCount;

public:
    Window(int id, int row, int col, int rowCount, int colCount);
    ~Window();

    bool addChild(Widget* child, int row, int col);
    bool isPositionFree(int row, int col);
    Widget* findChildById(int id);
    std::vector<Widget*> getChildren();
    int getRowCount() const { return m_rowCount; }
    int getColCount() const { return m_colCount; }
    Window* asWindow() override;
};

#endif
