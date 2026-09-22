#include "SimpleCombatResolver.h"

int SimpleCombatResolver::ResolveDamage(const std::string& action) {
    // Damage multiplier ini contoh elemen MUTABLE (lihat README).
    const int damageMultiplier = 2;
    return action == "attack" ? 5 * damageMultiplier : 0;
}
