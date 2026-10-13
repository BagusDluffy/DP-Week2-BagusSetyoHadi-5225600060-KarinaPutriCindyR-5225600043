#include <iostream>
#include "GameManager.h"

GameManager::GameManager() : playHandCommand(&handPlayer) {}

void GameManager::runSession()
{
    std::cout << "=== Run Started ===\n";

    Hand hand = handGenerator.generateHand();

    // Play Hand is triggered through the Command Pattern
    inputHandler.setCommand(&playHandCommand);
    inputHandler.executeCommand();

    int score = scoringRule.scoreHand(hand);
    bool win = blindRule.checkBlind(score);
    int reward = rewardRule.earnMoney(win, score);

    std::cout << "Money gained: " << reward << "\n";
    std::cout << "=== Run Ended ===\n";
}
