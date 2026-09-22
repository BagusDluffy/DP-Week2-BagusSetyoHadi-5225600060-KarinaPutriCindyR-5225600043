// main.cpp -- satu-satunya tempat yang tau kelas KONKRET mana yang dipakai.
// RunSession sendiri tidak pernah include header konkret ini.
//
// Cara compile (dari dalam folder Task1):
//   g++ -std=c++17 *.cpp -o run
//   ./run

#include <memory>
#include <ctime>
#include <cstdlib>
#include "RunSession.h"
#include "RandomInputGenerator.h"   // Modifikasi 1
#include "BasicScoringRule.h"
#include "ModifiedRewardRule.h"     // Modifikasi 2
#include "ShopSystem.h"

// Kalau mau lihat versi SEBELUM modifikasi, tinggal ganti include & tipe
// di bawah ini ke ManualInputGenerator.h / BasicRewardRule.h.
// RunSession.h/.cpp tidak perlu diubah sama sekali untuk switch ini.

int main() {
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    RunSession session(
        std::make_unique<RandomInputGenerator>(),
        std::make_unique<BasicScoringRule>(),
        std::make_unique<ModifiedRewardRule>(),
        std::make_unique<ShopSystem>()
    );

    session.StartRun(3);
    return 0;
}
