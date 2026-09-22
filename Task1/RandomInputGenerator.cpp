#include "RandomInputGenerator.h"
#include <cstdlib>

TurnInput RandomInputGenerator::Generate() {
    // Angka acak 1..10. srand() dipanggil sekali di main.cpp.
    return TurnInput{ (std::rand() % 10) + 1 };
}
