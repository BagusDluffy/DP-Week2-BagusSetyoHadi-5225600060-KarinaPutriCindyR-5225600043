#pragma once
#include "IInputGenerator.h"

// Implementasi awal: nilai tetap/deterministic, gampang buat testing awal.
class ManualInputGenerator : public IInputGenerator {
public:
    TurnInput Generate() override;
};
