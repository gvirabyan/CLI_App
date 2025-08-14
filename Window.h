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
    Window(int id,  int row , int col,int rowCount, int colCount);

    ~Window();

    bool addChild(Widget* child, int targetRow, int targetCol);

    bool isPositionFree(int targetRow, int targetCol);

    Widget* findChildById(int targetId);

    std::vector<Widget*> getChildren();
};

#endif 
