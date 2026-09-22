#pragma once
#include <memory>
#include "IInputGenerator.h"
#include "IScoringRule.h"
#include "IRewardRule.h"
#include "ShopSystem.h"

// RunSession = orkestrator murni.
// ATURAN KERAS (jangan dilanggar):
//   1. Urutan fase di StartRun() TIDAK BOLEH diubah.
//   2. Tidak boleh ada logic scoring/reward/input generation di sini.
//   3. Class ini hanya boleh tau tentang INTERFACE, bukan implementasi
//      konkret (makanya header ini cuma include I*.h, bukan
//      RandomInputGenerator.h atau ModifiedRewardRule.h).
class RunSession {
public:
    RunSession(std::unique_ptr<IInputGenerator> inputGen,
               std::unique_ptr<IScoringRule> scoringRule,
               std::unique_ptr<IRewardRule> rewardRule,
               std::unique_ptr<ShopSystem> shop);

    void StartRun(int totalRounds = 3);

private:
    std::unique_ptr<IInputGenerator> m_inputGen;
    std::unique_ptr<IScoringRule>    m_scoringRule;
    std::unique_ptr<IRewardRule>     m_rewardRule;
    std::unique_ptr<ShopSystem>      m_shop;
    int m_money = 0;
};
