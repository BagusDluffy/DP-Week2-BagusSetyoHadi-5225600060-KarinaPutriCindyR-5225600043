#include <iostream>
#include "ScoringRule.h"

ScoringRule::ScoringRule()
{
    // Chain: Flush -> Straight
    flushChecker.setNext(&straightChecker);
}

int ScoringRule::scoreHand(const Hand& hand)
{
    std::cout << "Calculating hand score...\n";

    HandRank rank = flushChecker.check(hand);
    int score = convertRankToScore(rank);

    std::cout << "Final score = " << score << "\n";
    return score;
}

int ScoringRule::convertRankToScore(HandRank rank)
{
    switch (rank)
    {
    case HandRank::FLUSH:
        return 20;
    case HandRank::STRAIGHT:
        return 15;
    case HandRank::HIGH_CARD:
    default:
        return 5;
    }
}
