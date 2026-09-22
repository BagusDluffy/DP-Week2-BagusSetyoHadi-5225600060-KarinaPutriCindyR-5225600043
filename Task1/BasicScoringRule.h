#pragma once
#include "IScoringRule.h"

// Implementasi paling sederhana: base score = nilai input apa adanya.
class BasicScoringRule : public IScoringRule {
public:
    int ComputeScore(const TurnInput& input) override;
};
