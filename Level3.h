#pragma once

#include "Level.h"
#include "Interface.h"

class Level3 : public Level {

public:
	Level3();
	~Level3();

	void start(Player& player, Enemy& enemy, Level& level, Interface& interface);
};
