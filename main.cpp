#include <iostream>
#include <sstream>
#include <vector>
#include "Window.h"
#include "CommandExecutor.h"

Window* rootWindow = nullptr;
int nextId = 1;

Widget* findWidget(int id) {
    if (!rootWindow) {
        return nullptr;
    }
    if (rootWindow->id == id) {
        return rootWindow;
    }
    return rootWindow->findChildById(id);
}

void printSuccessfulOperation(std::string text) {
    std::cerr<<"\033[32m" <<text <<"\033[0m"<<std::endl;
}

int main() {
    rootWindow = new Window(nextId++, -1, -1, 20, 20);

    CommandExecutor executor(rootWindow); 

    std::string line;
   executor.printSuccessfulOperation("Root window (ID: 1) created. Use 'add' command.");
    
    do {
        std::cout << " -> ";
        std::getline(std::cin, line);

        if (line == "") continue;

        if (line != "exit") {
            std::vector<std::string> commands;
            std::istringstream iss(line);
            std::string word;
            while (iss >> word) {
                commands.push_back(word);
            }
            executor.execute(commands);
        }

    } while (line != "exit");

    delete rootWindow;

    return 0;
}
