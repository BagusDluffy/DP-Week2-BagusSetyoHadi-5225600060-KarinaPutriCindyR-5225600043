#pragma once
#include "IActionHandler.h"

class SimpleActionHandler : public IActionHandler {
public:
    std::string PlayerAction(int roundNumber) override;
};
