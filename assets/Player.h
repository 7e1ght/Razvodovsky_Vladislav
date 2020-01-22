#pragma once
#include "Characters.h"
#include "Support.h"

class Player : public Characters
{
private:
	characters::DIRECTION _nextDir;

	void calcDirection() override;

	// for non-nest
	void changeDirection();

public:
	void resetPosition() override;

	Player();
	~Player() {}
};

