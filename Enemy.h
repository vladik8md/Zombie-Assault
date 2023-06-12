#pragma once

#include <string>

using namespace std;

class Enemy {

public:
	string name;
	int health;
	int damage;
	int armor;
	int nr;

	Enemy(string startingName = "", int startingHealth = 0, int startingDamage = 0, int startingArmor = 0, int startingNr = 0);
	virtual ~Enemy();
};
