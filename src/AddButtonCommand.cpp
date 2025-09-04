#include "AddButtonCommand.h"
#include <iostream>

AddButtonCommand::AddButtonCommand(Window* root) : m_root(root) {}

void AddButtonCommand::execute(const std::vector<std::string>& args) {
    if (args.size() < 5) {
        std::cerr << "Usage: add button <parent_id> <row> <col>\n";
        return;
    }

    int parentId = std::stoi(args[2]);
    int row = std::stoi(args[3]);
    int col = std::stoi(args[4]);

    Widget* parent = m_root->findChildById(parentId);
    Window* parentWindow = parent ? parent->asWindow() : nullptr;
    if (!parentWindow) {
        std::cerr << "Parent must be a Window!\n";
        return;
    }

    if (!parentWindow->isPositionFree(row, col)) {
        std::cerr << "Position not free!\n";
        return;
    }

    Widget* button = new Button(nextId++, row, col);
    parentWindow->addChild(button, row, col);
    std::cout << "Button added ID=" << button->id << std::endl;
}
