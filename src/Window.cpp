#include "Window.h"

Window::Window(int id, int row, int col, int rowCount, int colCount)
    : Widget(id, "Window", row, col), m_rowCount(rowCount), m_colCount(colCount) {
    grid.resize(rowCount, std::vector<Widget*>(colCount, nullptr));
}

Window::~Window() {
    for (auto child : children) delete child;
}

bool Window::addChild(Widget* child, int row, int col) {
    if (row < 0 || row >= m_rowCount || col < 0 || col >= m_colCount) return false;
    if (grid[row][col] != nullptr) return false;
    child->row = row;
    child->col = col;
    grid[row][col] = child;
    children.push_back(child);
    return true;
}

bool Window::isPositionFree(int row, int col) {
    if (row < 0 || row >= m_rowCount || col < 0 || col >= m_colCount) return false;
    return grid[row][col] == nullptr;
}

Widget* Window::findChildById(int id) {
    if (this->id == id) return this;
    for (auto child : children) {
        if (child->id == id) return child;
        if (Window* win = child->asWindow()) {
            Widget* found = win->findChildById(id);
            if (found) return found;
        }
    }
    return nullptr;
}

std::vector<Widget*> Window::getChildren() {
    return children;
}

Window* Window::asWindow() {
    return this;
}
