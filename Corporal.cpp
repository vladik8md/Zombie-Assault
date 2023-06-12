#include "Corporal.h"

Corporal::Corporal() {
	nr = rand() % 3 + 1;
	name = "Corporal";
	health = rand() % 11 + 35;
	damage = rand() % 6 + 10;
	armor = rand() % 3 + 2;
}

Corporal::~Corporal() {}

void Corporal::reset() {
	health = rand() % 11 + 35;
	damage = rand() % 6 + 10;
	armor = rand() % 3 + 2;
}