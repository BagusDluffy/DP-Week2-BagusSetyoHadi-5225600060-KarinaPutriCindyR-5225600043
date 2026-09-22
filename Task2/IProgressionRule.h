#pragma once

class IProgressionRule {
public:
    virtual ~IProgressionRule() = default;
    virtual int ComputeReward(int damage, int roundNumber) = 0;
};
