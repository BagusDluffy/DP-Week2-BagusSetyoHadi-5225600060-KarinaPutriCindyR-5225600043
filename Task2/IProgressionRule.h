#pragma once

// Interface untuk menentukan reward/skor yang didapat dari damage.
// Setara dengan IRewardRule di Task 1.
class IProgressionRule {
public:
    virtual ~IProgressionRule() = default;
    virtual int ComputeReward(int damage, int roundNumber) = 0;
};
