#include "AddWindowCommand.h"
#include <iostream>

AddWindowCommand::AddWindowCommand(Window* root) : m_root(root) {}

void AddWindowCommand::execute(const std::vector<std::string>& args) {
    if (args.size() < 7) {
        std::cerr << "\033[31mError: 'add window' requires 6 arguments.\033[0m" << std::endl;
        return;
    }

    int parentId = std::stoi(args[2]);
    int row = std::stoi(args[3]);
    int col = std::stoi(args[4]);
    int rowCount = std::stoi(args[5]);
    int colCount = std::stoi(args[6]);

    Widget* parentWidget = m_root->findChildById(parentId);
    Window* parentWindow = parentWidget ? parentWidget->asWindow() : nullptr;

    if (!parentWindow) {
        std::cerr << "\033[31mError: Parent must be a window.\033[0m" << std::endl;
        return;
    }

    if (!parentWindow->isPositionFree(row, col)) {
        std::cerr << "\033[33mPosition is not free. Widget not added.\033[0m" << std::endl;
        return;
    }

    Widget* newWin = new Window(nextId++, row, col, rowCount, colCount);
    parentWindow->addChild(newWin, row, col);
    std::cout << "\033[32mWindow added ID=" << newWin->id << "\033[0m" << std::endl;
}
