#pragma once
#include "TurnInput.h"

// Interface (kontrak) untuk menghasilkan input tiap ronde.
// RunSession cuma tau interface ini, TIDAK tau implementasi konkretnya
// (ManualInputGenerator atau RandomInputGenerator).
class IInputGenerator {
public:
    virtual ~IInputGenerator() = default;
    virtual TurnInput Generate() = 0;
};
