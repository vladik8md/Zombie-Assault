#pragma once

#include "Enemy.h"				

class Recruit : public Enemy {

public:
	Recruit();
	~Recruit();

	void reset();
};