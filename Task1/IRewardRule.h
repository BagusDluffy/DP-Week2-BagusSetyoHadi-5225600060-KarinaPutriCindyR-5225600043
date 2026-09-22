#pragma once

// Interface untuk menghitung reward (uang) dari base score.
// roundNumber disediakan supaya aturan reward bisa berbeda per ronde
// (dipakai di Modifikasi 2).
class IRewardRule {
public:
    virtual ~IRewardRule() = default;
    virtual int ComputeReward(int baseScore, int roundNumber) = 0;
};
