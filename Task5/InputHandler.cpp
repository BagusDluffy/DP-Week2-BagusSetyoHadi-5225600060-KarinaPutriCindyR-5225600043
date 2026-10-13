#include "InputHandler.h"

void InputHandler::setCommand(Command* cmd)
{
    command = cmd;
}

void InputHandler::executeCommand()
{
    if (command)
    {
        command->execute();
    }
}
