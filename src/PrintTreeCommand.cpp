#include "PrintTreeCommand.h"
#include <iostream>
#include <functional>

PrintTreeCommand::PrintTreeCommand(Window* root) : m_root(root) {}

void PrintTreeCommand::execute(const std::vector<std::string>& args) {
    if (!m_root) {
        return;
    }

    std::function<void(Widget*, int)> printTree = [&](Widget* widget, int level) {
        if (!widget) {
            return;
        }

        for (int i = 0; i < level; ++i) {
            std::cout << "  ";
        }

        std::cout << "\033[32m- " << widget->type << " (ID: " << widget->id << ")";
        if (level) {
            std::cout << " at [" << widget->row << ", " << widget->col << "]";
        }
        std::cout << "\033[0m" << std::endl;

        if (Window* win = widget->asWindow()) {
            for (auto child : win->getChildren()) {
                printTree(child, level + 1);
            }
        }
    };

    printTree(m_root, 0);
}
