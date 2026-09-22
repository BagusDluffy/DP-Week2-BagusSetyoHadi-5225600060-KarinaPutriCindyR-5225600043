#pragma once
#include "IActionHandler.h"

// CONTOH implementasi -- ganti sesuai game pretest kamu sendiri.
// Placeholder ini cuma memilih aksi "attack" tiap giliran.
class SimpleActionHandler : public IActionHandler {
public:
    std::string PlayerAction(int roundNumber) override;
};
