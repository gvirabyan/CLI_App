#ifndef PRINTTREECOMMAND_H
#define PRINTTREECOMMAND_H

#include "ICommand.h"
#include "Window.h"

class PrintTreeCommand : public ICommand {
    Window* m_root;
public:
    PrintTreeCommand(Window* root);
    void execute(const std::vector<std::string>& args) override;
};

#endif
