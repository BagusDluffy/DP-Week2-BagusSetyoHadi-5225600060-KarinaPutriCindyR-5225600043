#pragma once
#include "IInputGenerator.h"

// Modifikasi 1: implementasi baru yang menggantikan ManualInputGenerator.
// Perhatikan: file ini TIDAK menyentuh RunSession sama sekali.
class RandomInputGenerator : public IInputGenerator {
public:
    TurnInput Generate() override;
};
