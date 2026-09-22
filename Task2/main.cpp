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
        20
    );

    session.StartGame(5);
    return 0;
}
