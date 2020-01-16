#pragma once
#include "Characters.h"
#include "Support.h"

class Player : public Characters
{
private:
	characters::DIRECTION _nextDir;

	// for non-nest
	void changeDirection();

	void calcDirection() override;
public:

	Player(const char blocks[][gamefield::GAMEFIELD_COLUMN]);
};

