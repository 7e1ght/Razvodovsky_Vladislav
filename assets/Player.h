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
	void resetPosition() override;

	Player(char** blocks);
};

