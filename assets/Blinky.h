#pragma once
#include "Characters.h"
#include "Player.h" 
#include "Support.h"
#include "Ghost.h"

#include <memory>

class Blinky :
	public Ghost
{
public:

	Blinky(const char blocks[][gamefield::GAMEFIELD_COLUMN], std::shared_ptr<Player> player);
};

