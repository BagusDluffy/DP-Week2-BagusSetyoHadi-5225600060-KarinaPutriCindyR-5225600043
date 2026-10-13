#pragma once

// Command interface: every game action is wrapped as an object with execute()
class Command
{
public:
    virtual ~Command() = default;
    virtual void execute() = 0;
};
