#pragma once

#include "Command.h"

// Invoker: triggers a command without knowing what it does
class InputHandler
{
private:
    Command* command = nullptr;

public:
    void setCommand(Command* cmd);
    void executeCommand();
};
