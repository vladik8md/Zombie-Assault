#pragma once

#include "Level.h"
#include "Interface.h"

class Level2 : public Level {

public:
	Level2();
	~Level2();

	void start(Player& player, Enemy& enemy, Level& level, Interface& interface);
};