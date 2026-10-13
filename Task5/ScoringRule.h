#pragma once

#include "Hand.h"
#include "PokerHandChecker.h"
#include "FlushChecker.h"
#include "StraightChecker.h"

class ScoringRule
{
public:
    ScoringRule();
    int scoreHand(const Hand& hand);

private:
    FlushChecker flushChecker;
    StraightChecker straightChecker;

    int convertRankToScore(HandRank rank);
};
