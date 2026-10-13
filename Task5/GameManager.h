#pragma once

#include "HandGenerator.h"
#include "HandPlayer.h"
#include "ScoringRule.h"
#include "BlindRule.h"
#include "RewardRule.h"
#include "InputHandler.h"
#include "PlayHandCommand.h"

class GameManager
{
public:
    GameManager();
    void runSession();

private:
    HandGenerator handGenerator;
    HandPlayer handPlayer;
    ScoringRule scoringRule;
    BlindRule blindRule;
    RewardRule rewardRule;

    // Command Pattern: invoker + concrete command
    InputHandler inputHandler;
    PlayHandCommand playHandCommand;
};
