#pragma once
#include "TurnInput.h"

// Interface untuk menghitung base score dari input ronde ini.
class IScoringRule {
public:
    virtual ~IScoringRule() = default;
    virtual int ComputeScore(const TurnInput& input) = 0;
};
