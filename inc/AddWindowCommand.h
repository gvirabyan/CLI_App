#ifndef ADDWINDOWCOMMAND_H
#define ADDWINDOWCOMMAND_H

#include "ICommand.h"
#include "Window.h"
#include <vector>
#include <string>

extern int nextId;

class AddWindowCommand : public ICommand {
    Window* m_root;
public:
    AddWindowCommand(Window* root);
    void execute(const std::vector<std::string>& args) override;
};


#endif
