#ifndef WIDGET_H
#define WIDGET_H

#include <string>

class Window;

class Widget {
public:
    int id;
    int row ;
    int col ;
    std::string type;

    Widget(int id, const std::string& type, int row , int col);

    virtual ~Widget() = default;

    Window* asWindow();
};

#endif 
