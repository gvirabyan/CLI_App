#ifndef ADDTEXTCOMMAND_H
#define ADDTEXTCOMMAND_H

#include "ICommand.h"
#include "Window.h"
#include "Text.h"

extern int nextId;

class AddTextCommand : public ICommand {
    Window* m_root;
public:
    AddTextCommand(Window* root);
    void execute(const std::vector<std::string>& args) override;
};

#endif
