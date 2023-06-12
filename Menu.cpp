#include <iostream>
#include <fstream>
#include <string>

#include "Menu.h"

using namespace std;

Menu::Menu() {}

Menu::~Menu() {}

void Menu::showMenu() {

	ifstream inputFile("savegame.txt");
	string levelName;
	if (inputFile.is_open()) {
		getline(inputFile, levelName);
		inputFile.close();
	}

	if (levelName != "Recruit" && levelName != "Corporal" && levelName != "Major" && levelName != "General")
	{
		levelName = "Recruit";
	}

	cout << endl << " Text Mode Game | Zombie Assault" << endl << endl;
	cout << " 1. Joc nou" << endl;


	if (levelName == "Recruit")
		cout << " 2. Continua jocul" << endl;
	else
		cout << " 2. Continua jocul ( Level " << levelName << " )" << endl;


	cout << " 9. Informatii despre autor" << endl;
	cout << " 0. Exit" << endl << endl;
}

int Menu::getOpt() {
	string opt = "";

	while (opt != "1" && opt != "2" && opt != "9" && opt != "0")
	{
		cout << " Optiunea aleasa: ";
		cin >> opt;
	}
	return stoi(opt);
}