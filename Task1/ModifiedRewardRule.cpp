#include "ModifiedRewardRule.h"

int ModifiedRewardRule::ComputeReward(int baseScore, int roundNumber) {
    // Aturan: ronde genap -> reward dilipatgandakan (bonus ronde genap).
    //         ronde ganjil -> reward = baseScore + 2 (bonus flat).
    if (roundNumber % 2 == 0) {
        return baseScore * 2;
    }
    return baseScore + 2;
}
