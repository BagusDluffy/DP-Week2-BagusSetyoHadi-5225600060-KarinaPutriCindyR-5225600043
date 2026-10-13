#include "RandomInputGenerator.h"
#include <cstdlib>

TurnInput RandomInputGenerator::Generate() {
    return TurnInput{ (std::rand() % 13) + 1 };
}
