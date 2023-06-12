#include <iostream>
#include <fstream>
#include <ctime>

#include "Interface.h"
#include "Menu.h"
#include "Credits.h"
#include "Level1.h"
#include "Level2.h"
#include "Level3.h"
#include "Level4.h"
#include "Recruit.h"
#include "Corporal.h"
#include "Major.h"
#include "General.h"

using namespace std;

int main() {

MENU:
	system("cls");

	Level level;

	Player player;

	Interface interface;

	Enemy enemy;

	Menu menu;
	menu.showMenu();

	int opt = menu.getOpt();

	if (opt == 1)
	{
	LEVEL1:
		ofstream file("savegame.txt", ofstream::trunc);
		if (file.is_open()) {
			file.close();
		}

		Level1 level1;
		Recruit recruit;
		level1.start(player, recruit, level, interface);

		Level2 level2;
		Corporal corporal;
		level2.start(player, corporal, level, interface);

		Level3 level3;
		Major major;
		level3.start(player, major, level, interface);

		Level4 level4;
		General general;
		level4.start(player, general, level, interface);
	}

	else if (opt == 2) {
		ifstream inputFile("savegame.txt");
		string levelTxt;
		if (inputFile.is_open()) {
			getline(inputFile, levelTxt);
			inputFile.close();
		}

		if (levelTxt == "Corporal") {
			Level2 level2;
			Corporal corporal;
			level.load(enemy, player);
			level2.start(player, corporal, level, interface);

			Level3 level3;
			Major major;
			level3.start(player, major, level, interface);

			Level4 level4;
			General general;
			level4.start(player, general, level, interface);
		}
		else if (levelTxt == "Major") {
			Level3 level3;
			Major major;
			level.load(enemy, player);
			level3.start(player, major, level, interface);

			Level4 level4;
			General general;
			level4.start(player, general, level, interface);
		}
		else if (levelTxt == "General") {
			Level4 level4;
			General general;
			level.load(enemy, player);
			level4.start(player, general, level, interface);
		}
		else
		{
			system("cls");
			cout << endl << " Text Mode Game | Zombie Assault" << endl << endl;
			cout << " Nu s-a gasit nici un savegame. Jocul va incepe de la inceput." << endl;
			level.pause();
			goto LEVEL1;
		}
	}

	else if (opt == 9)
	{
		system("cls");

		Credits credits;
		credits.showCredits();

		level.pause();
		goto MENU;
	}
	else {
		system("cls");
		cout << endl << " Text Mode Game | Zombie Assault" << endl << endl;
		cout << " Pacat! Nu uitati sa reveniti in aceasta calatorie minunata!" << endl;
	}
	return 0;
}
