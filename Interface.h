#pragma once

#include "Player.h"
#include "Enemy.h"
#include "Level.h"

class Interface {

public:
    int interfaceLevel;
    Interface();
    ~Interface();

    void showPlayerInterface(Player& player, Level& level, Enemy& enemy);
    void showBattleInterface(Player& player, Enemy& enemy, Level& level);
};