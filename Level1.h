#pragma once

#include "Level.h"
#include "Interface.h"

class Level1 : public Level {

public:
	Level1();
	~Level1();

	void start(Player& player, Enemy& enemy, Level& level, Interface& interface);
};

