#ifndef ADDBUTTONCOMMAND_H
#define ADDBUTTONCOMMAND_H

#include "ICommand.h"
#include "Window.h"
#include "Button.h"

extern int nextId;

class AddButtonCommand : public ICommand {
    Window* m_root;
public:
    AddButtonCommand(Window* root);
    void execute(const std::vector<std::string>& args) override;
};

#endif
