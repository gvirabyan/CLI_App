#include "AddTextCommand.h"
#include <iostream>

AddTextCommand::AddTextCommand(Window* root) : m_root(root) {}

void AddTextCommand::execute(const std::vector<std::string>& args) {
    if (args.size() < 5) {
        std::cerr << "Usage: add text <parent_id> <row> <col>\n";
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

    Widget* text = new Text(nextId++, row, col);
    parentWindow->addChild(text, row, col);
    std::cout << "Text added ID=" << text->id << std::endl;
}
