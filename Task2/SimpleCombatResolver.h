#pragma once
#include "ICombatResolver.h"

// CONTOH implementasi -- sesuaikan dengan mekanik game kamu.
class SimpleCombatResolver : public ICombatResolver {
public:
    int ResolveDamage(const std::string& action) override;
};
