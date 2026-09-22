#pragma once
#include <string>

class IActionHandler {
public:
    virtual ~IActionHandler() = default;
    virtual std::string PlayerAction(int roundNumber) = 0;
};
