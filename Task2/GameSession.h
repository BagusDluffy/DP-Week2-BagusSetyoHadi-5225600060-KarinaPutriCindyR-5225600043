#pragma once
#include <memory>
#include "IActionHandler.h"
#include "ICombatResolver.h"
#include "IProgressionRule.h"

// GameSession = orkestrator core loop, sama peran-nya seperti RunSession
// di Task 1. Urutan fase di StartGame() adalah INVARIANT:
//   1. Player action
//   2. System resolves (combat/damage)
//   3. Reward dihitung & state di-update
//   4. Cek kondisi menang/kalah
//   5. Repeat sampai game over
//
// GameSession TIDAK boleh berisi logic combat/reward, hanya urutan panggilan.
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
