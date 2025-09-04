#include "Widget.h"
#include "Window.h"

Widget::Widget(int id, const std::string& type, int row, int col)
    : id(id), type(type), row(row), col(col) {}

Window* Widget::asWindow() {
    return nullptr;
}
