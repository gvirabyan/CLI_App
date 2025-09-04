#include "CommandExecutor.h"
#include <iostream>

CommandExecutor::CommandExecutor(Window* root) : m_root(root) {}

void CommandExecutor::registerCommand(const std::string& name, ICommand* cmd) {
    m_commands[name] = cmd;
}

void CommandExecutor::execute(const std::vector<std::string>& args) {
    if (args.empty()) {
        return;
    }

    std::string key = args[0];
    if (args.size() > 1) {
        key += " " + args[1];
    }

    auto it = m_commands.find(key);
    if (it != m_commands.end()) {
        it->second->execute(args);
    } else {
        std::cerr << "Unknown command: " << key << std::endl;
    }
}

Window* CommandExecutor::getRoot() {
    return m_root;
}

void CommandExecutor::printWidgetTree(Widget* widget, int level) {
    if (!widget) {
        return;
    }

    for (int i = 0; i < level; ++i) {
        std::cout << "  ";
    }

    std::cout << "- " << widget->type << " (ID: " << widget->id << ")";
    if (level) {
        std::cout << " at [" << widget->row << ", " << widget->col << "]";
    }
    std::cout << std::endl;

    if (Window* w = widget->asWindow()) {
        for (auto child : w->getChildren()) {
            printWidgetTree(child, level + 1);
        }
    }
}
