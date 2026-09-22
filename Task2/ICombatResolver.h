#pragma once
#include <string>

class ICombatResolver {
public:
    virtual ~ICombatResolver() = default;
    virtual int ResolveDamage(const std::string& action) = 0;
};
