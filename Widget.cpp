#include "Widget.h"
#include "Window.h"

using namespace std;

Widget::Widget(int id, const string& type, int row, int col)
    : id(id), type(type), row(row), col(col) {}

Window* Widget::asWindow() {
    return dynamic_cast<Window*>(this);
}
