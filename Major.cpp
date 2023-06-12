#include "Major.h"

Major::Major() {
	nr = rand() % 3 + 1;
	name = "Major";
	health = rand() % 11 + 45;
	damage = rand() % 6 + 15;
	armor = rand() % 5 + 4;
}

Major::~Major() {}

void Major::reset() {
	health = rand() % 11 + 45;
	damage = rand() % 6 + 15;
	armor = rand() % 5 + 4;
}