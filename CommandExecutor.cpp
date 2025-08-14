#include "CommandExecutor.h"
#include <iostream>
#include <sstream>

extern int nextId;
extern Widget* findWidget(int id);

CommandExecutor::CommandExecutor(Window* root) : rootWindow(root) {}

void CommandExecutor::printError(const std::string& text) {
    std::cerr<<"\033[31m" <<text <<"\033[0m"<<std::endl;
}
void CommandExecutor::printWarning(const std::string& text){
    std::cerr<<"\033[33m" <<text <<"\033[0m"<<std::endl;
}
void CommandExecutor::printSuccessfulOperation(const std::string& text){
    std::cerr<<"\033[32m" <<text <<"\033[0m"<<std::endl;
}

void CommandExecutor::printHelp() {
    std::cout << "Available Commands:" << std::endl;
    std::cout << "  add window <parent_id> <rowPosition> <colPosition> <rows> <cols> - Add a new window." << std::endl;
    std::cout << "  add table <parent_id> <rowPosition> <colPosition>               - Add a new table." << std::endl;
    std::cout << "  add button <parent_id> <rowPosition> <colPosition>              - Add a new button." << std::endl;
    std::cout << "  add text <parent_id> <rowPosition> <colPosition>                - Add a new text widget." << std::endl;
    std::cout << "  print                                                           - Prints the widget tree." << std::endl;
    std::cout << "  exit                                                            - Exit the program." << std::endl;
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

    if (Window* window = widget->asWindow()) {
        for (Widget* child : window->getChildren()) {
            printWidgetTree(child, level + 1);
        }
    }
}

void CommandExecutor::addWidget(const std::vector<std::string>& commands) {
    if (commands.size() < 5) {
        printError("Error: 'add' command requires at least 4 arguments.");
        return;
    }

    std::string type = commands[1];
    int parentId = std::stoi(commands[2]);
    int rowPosition = std::stoi(commands[3]);
    int colPosition = std::stoi(commands[4]);
    
    Widget* parentWidget = findWidget(parentId);
    if (!parentWidget) {
        printError("Error: Parent widget with the specified ID not found!");
        return;
    }

    Window* parentWindow = parentWidget->asWindow();
    
    if(parentWindow == nullptr) {
        printError("Error: Parent widget must be a window!");
        return;
    }
    
    Widget* newWidget = nullptr;
    if (type == "window") {
        if (commands.size() < 7) {
            printError("Error: 'add window' requires 6 arguments .");
            return;
        }
        int rowCount = std::stoi(commands[5]);
        int colCount = std::stoi(commands[6]);
        newWidget = new Window(nextId++, rowPosition, colPosition, rowCount, colCount);
    } else if (type == "table") {
        newWidget = new Table(nextId++, rowPosition, colPosition);
    } else if (type == "button") {
        newWidget = new Button(nextId++, rowPosition, colPosition);
    } else if (type == "text") {
        newWidget = new Text(nextId++, rowPosition, colPosition);
    } else {
        printError("Error: Unknown widget type.");
        return;
    }

    if (newWidget) {
        if (!parentWindow->isPositionFree(rowPosition, colPosition)) {
            printWarning("Position is not free. Widget not added.");
            delete newWidget;
            return;
        }
        parentWindow->addChild(newWidget, rowPosition, colPosition);
        printSuccessfulOperation(newWidget->type + " (ID: " + std::to_string(newWidget->id) + ") added to Window " + std::to_string(parentId) + ".");
    }
}


void CommandExecutor::execute(const std::vector<std::string>& commands) {
    if (commands.empty()) {
        return;
    }
    std::string command = commands[0];

    if (command == "add") {
        addWidget(commands);
    } else if(command == "--help") {
        printHelp();
    } else if (command == "print") {
        printWidgetTree(rootWindow, 0);
    } else {
        printError("Unknown command. Use --help to show all commands.");
    }
}
