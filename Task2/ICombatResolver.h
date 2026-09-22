#pragma once
#include <string>

// Interface untuk menghitung hasil dari sebuah aksi (mis. damage).
// Ini setara dengan IScoringRule di Task 1.
class ICombatResolver {
public:
    virtual ~ICombatResolver() = default;
    virtual int ResolveDamage(const std::string& action) = 0;
};
