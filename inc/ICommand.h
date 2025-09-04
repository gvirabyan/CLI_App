#ifndef ICOMMAND_H
#define ICOMMAND_H

#include <vector>
#include <string>

class ICommand {
public:
    virtual ~ICommand() ;
    virtual void execute(const std::vector<std::string>& args) = 0;
};

#endif
