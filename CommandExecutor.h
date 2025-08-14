#ifndef COMMANDEXECUTOR_H
#define COMMANDEXECUTOR_H

#include <vector>
#include <string>
#include "Window.h"
#include "Widget.h"
#include "Table.h"
#include "Button.h"
#include "Text.h"

class CommandExecutor {
public:
    CommandExecutor(Window* root);
    void execute(const std::vector<std::string>& commands);

private:
    Window* rootWindow;
    
    void addWidget(const std::vector<std::string>& commands);
    void printHelp();
    void printWidgetTree(Widget* widget, int level);
    
    void printError(const std::string& text);
    void printWarning(const std::string& text);
    void printSuccessfulOperation(const std::string& text);
};

#endif
