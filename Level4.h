#pragma once

#include "Level.h"
#include "Interface.h"

class Level4 : public Level {

public:
	Level4();
	~Level4();

	void start(Player& player, Enemy& enemy, Level& level, Interface& interface);
};