#include <iostream>
#include <fstream>
#include <cstdlib>

#include "Level3.h"
#include "Interface.h"
#include "Major.h"

using namespace std;

Level3::Level3() {}

Level3::~Level3() {}

void Level3::start(Player& player, Enemy& enemy, Level& level, Interface& interface)
{
	system("cls");

	level.story(enemy, player);

	level.pause();
	system("cls");

	Major major;
	interface.showPlayerInterface(player, level, enemy);

	level.setEndLevel(false);

	while (player.health > 0 && enemy.nr > 0 && !level.endLevel())
		level.choice(player, major);

	system("cls");

	level.final(enemy, player);

	level.pause();
	system("cls");

	enemy.name = "General";

	level.save(enemy, player);
}