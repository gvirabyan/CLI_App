#include "AddTableCommand.h"
#include <iostream>

AddTableCommand::AddTableCommand(Window* root) : m_root(root) {}

void AddTableCommand::execute(const std::vector<std::string>& args) {
    if (args.size() < 5) {
        std::cerr << "\033[31mUsage: add table <parent_id> <row> <col>\033[0m\n";
        return;
    }

    int parentId = std::stoi(args[2]);
    int row = std::stoi(args[3]);
    int col = std::stoi(args[4]);

    Widget* parent = m_root->findChildById(parentId);
    Window* parentWindow = parent ? parent->asWindow() : nullptr;
    if (!parentWindow) {
        std::cerr << "\033[31mError: Parent must be a Window!\033[0m\n";
        return;
    }

    if (!parentWindow->isPositionFree(row, col)) {
        std::cerr << "\033[33mWarning: Position not free!\033[0m\n";
        return;
    }

    Widget* table = new Table(nextId++, row, col);
    parentWindow->addChild(table, row, col);
    std::cout << "\033[32mTable added ID=" << table->id << "\033[0m\n";
}
