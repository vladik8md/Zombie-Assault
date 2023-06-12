#include "Enemy.h"

Enemy::Enemy(string startingName, int startingHealth, int startingDamage, int startingArmor, int startingNr)
    : name(startingName), health(startingHealth), damage(startingDamage), armor(startingArmor), nr(startingNr) {}

Enemy::~Enemy() {}