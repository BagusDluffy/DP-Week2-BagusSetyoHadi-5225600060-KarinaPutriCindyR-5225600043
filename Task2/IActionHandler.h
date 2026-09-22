#pragma once
#include <string>

// Interface untuk menangani aksi yang dipilih pemain di setiap giliran.
// GameSession tidak tau bagaimana aksi diproses, cuma manggil interface ini.
class IActionHandler {
public:
    virtual ~IActionHandler() = default;
    virtual std::string PlayerAction(int roundNumber) = 0;
};
