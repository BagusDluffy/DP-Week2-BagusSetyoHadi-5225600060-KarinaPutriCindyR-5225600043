#include "SimpleCombatResolver.h"

int SimpleCombatResolver::ResolveDamage(const std::string& action) {
    const int damageMultiplier = 2;
    return action == "attack" ? 5 * damageMultiplier : 0;
}
