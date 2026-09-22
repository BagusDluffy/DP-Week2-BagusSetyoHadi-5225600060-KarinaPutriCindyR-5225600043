#include "GameSession.h"
#include <iostream>

GameSession::GameSession(std::unique_ptr<IActionHandler> actionHandler,
                          std::unique_ptr<ICombatResolver> combatResolver,
                          std::unique_ptr<IProgressionRule> progressionRule,
                          int startingHp)
    : m_actionHandler(std::move(actionHandler)),
      m_combatResolver(std::move(combatResolver)),
      m_progressionRule(std::move(progressionRule)),
      m_hp(startingHp) {}

bool GameSession::IsGameOver(int round, int maxRounds) const {
    return m_hp <= 0 || round > maxRounds;
}

void GameSession::StartGame(int maxRounds) {
    std::cout << "=== GAME START (HP: " << m_hp << ") ===\n";

    int round = 1;
    while (!IsGameOver(round, maxRounds)) {
        std::cout << "\nRound " << round << "\n";

        std::string action = m_actionHandler->PlayerAction(round);
        std::cout << "[ACTION] player chose: " << action << "\n";

        int damage = m_combatResolver->ResolveDamage(action);
        std::cout << "[RESOLVE] damage dealt: " << damage << "\n";

        int reward = m_progressionRule->ComputeReward(damage, round);
        m_score += reward;
        m_hp -= 2;
        std::cout << "[UPDATE] score: " << m_score << " | hp: " << m_hp << "\n";

        ++round; // 5. Repeat
    }

    std::cout << "\n=== GAME END ===\n";
    std::cout << "Final score: " << m_score << " | Final HP: " << m_hp << "\n";
}
