#include "Recruit.h"

Recruit::Recruit() {
	nr = rand() % 3 + 1;
	name = "Recruit";
	health = rand() % 11 + 25;
	damage = rand() % 6 + 5;
	armor = rand() % 2 + 1;
}

Recruit::~Recruit() {}

void Recruit::reset() {
	health = rand() % 11 + 25;
	damage = rand() % 6 + 5;
	armor = rand() % 2 + 1;
}