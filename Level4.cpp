#include <iostream>
#include <fstream>
#include <cstdlib>

#include "Level4.h"
#include "Interface.h"
#include "General.h"

using namespace std;

Level4::Level4() {}

Level4::~Level4() {}

void Level4::start(Player& player, Enemy& enemy, Level& level, Interface& interface)
{
	system("cls");

	level.story(enemy, player);

	level.pause();
	system("cls");

	General general;
	interface.showPlayerInterface(player, level, enemy);

	level.setEndLevel(false);

	while (player.health > 0 && enemy.nr > 0 && !level.endLevel())
		level.choice(player, general);

	system("cls");

	level.final(enemy, player);

	level.pause();
	system("cls");

	ofstream outputFile("savegame.txt");

	if (outputFile.is_open())
		outputFile.close();

	cout << endl;
}