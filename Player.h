#pragma once

#include <string>

using namespace std;

class Player {

public:
	string name;
	int health;
	int damage;
	int armor;
	int firstAidKits;

	Player(string startingName = "", int startingHealth = 100, int startingDamage = 10, int startingArmor = 0, int startingFirstAidKits = 0);

	~Player();
};

