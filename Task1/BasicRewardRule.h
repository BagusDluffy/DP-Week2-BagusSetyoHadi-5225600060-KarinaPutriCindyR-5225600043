#pragma once
#include "IRewardRule.h"

// Versi awal (sebelum Modifikasi 2): reward = base score, apa adanya.
class BasicRewardRule : public IRewardRule {
public:
    int ComputeReward(int baseScore, int roundNumber) override;
};
