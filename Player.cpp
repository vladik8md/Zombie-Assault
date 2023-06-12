#include "Player.h"

Player::Player(string startingName, int startingHealth, int startingDamage, int startingArmor, int startingFirstAidKits)
	: health(startingHealth), damage(startingDamage), armor(startingArmor), firstAidKits(startingFirstAidKits) {}

Player::~Player() {}