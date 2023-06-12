#pragma once

#include "Player.h"
#include "Enemy.h"

class Level {

public:
	bool end;
	Level(bool startingEnd = false);
	~Level();

	void pause();

	void setPlayerName(string& playerName, Player& player);
	void save(Enemy& enemy, Player& player);
	void load(Enemy& enemy, Player& player);
	void story(Enemy& enemy, Player& player);
	void choice(Player& player, Enemy& enemy);
	void battle(Player& player, Enemy& enemy);
	void resetEnemy(Enemy& enemy);
	void final(Enemy& enemy, Player& player);
	bool endLevel();
	void setEndLevel(bool value);
};