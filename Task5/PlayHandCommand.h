#pragma once

#include "Command.h"
#include "HandPlayer.h"

// Concrete command: the "Play Hand" action. Receiver = HandPlayer
class PlayHandCommand : public Command
{
private:
    HandPlayer* handPlayer;

public:
    PlayHandCommand(HandPlayer* player) : handPlayer(player) {}

    void execute() override
    {
        handPlayer->playHand();
    }
};
