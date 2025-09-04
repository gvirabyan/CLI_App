#include <iostream>
#include <sstream>
#include <vector>
#include "Window.h"
#include "CommandExecutor.h"
#include "AddWindowCommand.h"
#include "AddTableCommand.h"
#include "AddButtonCommand.h"
#include "AddTextCommand.h"
#include "PrintTreeCommand.h"

int nextId = 1;

int main() {
    Window* root = new Window(nextId++, -1, -1, 20, 20);
    std::cout << "\033[32mRoot window created (ID: " << root->id << ")\033[0m\n";

    CommandExecutor executor(root);
    executor.registerCommand("add window", new AddWindowCommand(root));
    executor.registerCommand("add table",  new AddTableCommand(root));
    executor.registerCommand("add button", new AddButtonCommand(root));
    executor.registerCommand("add text",   new AddTextCommand(root));
    executor.registerCommand("print", new PrintTreeCommand(root));

    std::string line;
    do {
        std::cout << "-> ";
        std::getline(std::cin, line);
        if (line.empty()) continue;

        if (line != "exit") {
            std::vector<std::string> args;
            std::istringstream iss(line);
            std::string word;
            while (iss >> word) args.push_back(word);
            executor.execute(args);
        }

    } while (line != "exit");

    delete root;
    return 0;
}
