#include "RunSession.h"
#include <iostream>

RunSession::RunSession(std::unique_ptr<IInputGenerator> inputGen,
                        std::unique_ptr<IScoringRule> scoringRule,
                        std::unique_ptr<IRewardRule> rewardRule,
                        std::unique_ptr<ShopSystem> shop)
    : m_inputGen(std::move(inputGen)),
      m_scoringRule(std::move(scoringRule)),
      m_rewardRule(std::move(rewardRule)),
      m_shop(std::move(shop)) {}

void RunSession::StartRun(int totalRounds) {
    std::cout << "=== RUN START ===\n";

    for (int round = 1; round <= totalRounds; ++round) {
        std::cout << "\nRound " << round << "\n";

        // Fase 1: Generate input -- didelegasikan, bukan logic sendiri.
        TurnInput input = m_inputGen->Generate();
        std::cout << "[PLAY] input generated: " << input.value << "\n";

        // Fase 2: Compute base score.
        int baseScore = m_scoringRule->ComputeScore(input);
        std::cout << "[SCORE] base score: " << baseScore << "\n";

        // Fase 3: Compute reward.
        int reward = m_rewardRule->ComputeReward(baseScore, round);

        // Fase 4: Update money.
        m_money += reward;
        std::cout << "[REWARD] gain: " << reward << " | money: " << m_money << "\n";

        // Fase 5: Shop phase.
        m_shop->OfferItem(round);

        // Fase 6: Advance round (dilakukan otomatis oleh for-loop).
    }

    std::cout << "\n=== RUN END ===\n";
    std::cout << "Final money: " << m_money << "\n";
}
