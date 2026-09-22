#pragma once
#include "IProgressionRule.h"

class SimpleProgressionRule : public IProgressionRule {
public:
    int ComputeReward(int damage, int roundNumber) override;
};
