#include "Window.h"

using namespace std;

Window::Window(int id, int row, int col, int rowCount, int colCount)
    : Widget(id, "Window", row, col),m_rowCount(rowCount),m_colCount(colCount) {
    grid.resize(rowCount, vector<Widget*>(colCount, nullptr));
}

Window::~Window() {
    for (Widget* child : children) {
        delete child;
    }
}

bool Window::addChild(Widget* child, int rowPosition, int colPosition) {
    if (rowPosition < 0 || rowPosition >= m_rowCount || colPosition < 0 || colPosition >= m_colCount) {
        return false;
    }
    if (grid[rowPosition][colPosition] != nullptr) {
        return false;
    }

    child->row = rowPosition;
    child->col = colPosition;
    grid[rowPosition][colPosition] = child;
    children.push_back(child);
    return true;
}

bool Window::isPositionFree(int targetRow, int targetCol) {

    return grid[targetRow][targetCol] == nullptr;
}

Widget* Window::findChildById(int targetId) {
    if (this->id == targetId) {
        return this;
    }
    for (const auto& child : children) {
        if (child->id == targetId) {
            return child;
        }
        if (Window* childAsWindow = child->asWindow()) {
            if (Widget* found = childAsWindow->findChildById(targetId)) {
                return found;
            }
        }
    }
    return nullptr;
}

std::vector<Widget*> Window::getChildren() {
        return children;
    }
