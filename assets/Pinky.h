#pragma once
#include "Ghost.h"
#include "Support.h"
#include "Player.h"
#include "PinkyChase.h"

class Pinky :
	public Ghost
{
public:

	Pinky(const char blocks[][gamefield::GAMEFIELD_COLUMN], std::shared_ptr<Player> player);
};

