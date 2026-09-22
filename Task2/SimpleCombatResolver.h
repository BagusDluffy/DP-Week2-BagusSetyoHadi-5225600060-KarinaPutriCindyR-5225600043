#pragma once
#include "ICombatResolver.h"

class SimpleCombatResolver : public ICombatResolver {
public:
    int ResolveDamage(const std::string& action) override;
};
