#include <iostream>
#include <fstream>
#include <cstdlib>

#include "Level1.h"
#include "Interface.h"
#include "Recruit.h"

using namespace std;

Level1::Level1() {}

Level1::~Level1() {}

void Level1::start(Player& player, Enemy& enemy, Level& level, Interface& interface)
{
	system("cls");

	string playerName;
	level.setPlayerName(playerName, player);

	system("cls");

	level.story(enemy, player);

	level.pause();
	system("cls");

	Recruit recruit;
	interface.showPlayerInterface(player, level, enemy);

	while (player.health > 0 && enemy.nr > 0 && !level.endLevel())
		level.choice(player, recruit);

	system("cls");

	level.final(enemy, player);

	level.pause();
	system("cls");

	enemy.name = "Corporal";

	level.save(enemy, player);
}