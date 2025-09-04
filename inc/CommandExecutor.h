#ifndef COMMANDEXECUTOR_H
#define COMMANDEXECUTOR_H

#include "ICommand.h"
#include "Window.h"
#include <unordered_map>
#include <string>

class CommandExecutor {
    std::unordered_map<std::string, ICommand*> m_commands;
    Window* m_root;
public:
    CommandExecutor(Window* root);
    void registerCommand(const std::string& name, ICommand* cmd);
    void execute(const std::vector<std::string>& args);
    void printWidgetTree(Widget* widget, int level = 0);
    Window* getRoot();
};

#endif
