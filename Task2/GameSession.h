#pragma once
#include <memory>
#include "IActionHandler.h"
#include "ICombatResolver.h"
#include "IProgressionRule.h"

class GameSession {
public:
    GameSession(std::unique_ptr<IActionHandler> actionHandler,
                std::unique_ptr<ICombatResolver> combatResolver,
                std::unique_ptr<IProgressionRule> progressionRule,
                int startingHp = 20);

    void StartGame(int maxRounds = 5);

private:
    bool IsGameOver(int round, int maxRounds) const;

    std::unique_ptr<IActionHandler>   m_actionHandler;
    std::unique_ptr<ICombatResolver>  m_combatResolver;
    std::unique_ptr<IProgressionRule> m_progressionRule;
    int m_hp;
    int m_score = 0;
};
