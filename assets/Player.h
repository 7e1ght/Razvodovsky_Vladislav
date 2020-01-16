#pragma once
#include "Characters.h"

class Player : public Characters
{
private:
	DIRECTION nextDir;
public:
	void move();

	Player(const char blocks[][gamefield::GAMEFIELD_COLUMN]);
};

