#include "General.h"

General::General() {
	nr = rand() % 3 + 1;
	name = "General";
	health = rand() % 11 + 45;
	damage = rand() % 6 + 15;
	armor = rand() % 9 + 8;
}

General::~General() {}

void General::reset() {
	health = rand() % 11 + 45;
	damage = rand() % 6 + 15;
	armor = rand() % 9 + 8;
}