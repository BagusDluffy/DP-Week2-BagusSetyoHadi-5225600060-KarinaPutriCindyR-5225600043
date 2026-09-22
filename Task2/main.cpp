// main.cpp -- wiring untuk Task 2.
// GANTI SimpleActionHandler / SimpleCombatResolver / SimpleProgressionRule
// di sini kalau kamu mau pasang mekanik game pretest kamu sendiri.
//
// Compile: g++ -std=c++17 *.cpp -o game
// Run:     ./game

#include <memory>
#include "GameSession.h"
#include "SimpleActionHandler.h"
#include "SimpleCombatResolver.h"
#include "SimpleProgressionRule.h"

int main() {
    GameSession session(
        std::make_unique<SimpleActionHandler>(),
        std::make_unique<SimpleCombatResolver>(),
        std::make_unique<SimpleProgressionRule>(),
        20 // starting HP
    );

    session.StartGame(5);
    return 0;
}
