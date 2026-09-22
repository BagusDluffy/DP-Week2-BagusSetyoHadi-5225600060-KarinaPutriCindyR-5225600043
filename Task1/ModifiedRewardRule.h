#pragma once
#include "IRewardRule.h"

// Modifikasi 2: reward TIDAK LAGI sama dengan base score.
// Lagi-lagi, file ini tidak menyentuh RunSession.
class ModifiedRewardRule : public IRewardRule {
public:
    int ComputeReward(int baseScore, int roundNumber) override;
};
