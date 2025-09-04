#ifndef ADDTABLECOMMAND_H
#define ADDTABLECOMMAND_H

#include "ICommand.h"
#include "Window.h"
#include "Table.h"

extern int nextId;

class AddTableCommand : public ICommand {
    Window* m_root;
public:
    AddTableCommand(Window* root);
    void execute(const std::vector<std::string>& args) override;
};

#endif
