#include <iostream>
#include <fstream>
#include <cstdlib>

#include "Level2.h"
#include "Interface.h"
#include "Corporal.h"

using namespace std;

Level2::Level2() {}

Level2::~Level2() {}

void Level2::start(Player& player, Enemy& enemy, Level& level, Interface& interface)
{
	system("cls");

	level.story(enemy, player);

	level.pause();
	system("cls");

	Corporal corporal;

	interface.showPlayerInterface(player, level, enemy);

	level.setEndLevel(false);

	while (player.health > 0 && enemy.nr > 0 && !level.endLevel())
		level.choice(player, corporal);

	system("cls");

	level.final(enemy, player);

	level.pause();
	system("cls");

	level.save(enemy, player);
}