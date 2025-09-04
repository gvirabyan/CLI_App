#ifndef WIDGET_H
#define WIDGET_H

#include <string>

class Window;

class Widget {
public:
    int id;
    std::string type;
    int row;
    int col;

    Widget(int id, const std::string& type, int row, int col);
    virtual ~Widget() = default;
    virtual Window* asWindow();
};

#endif
