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

	void resetPosition() override;
	void resetAppearance() override;

	Blinky(char** blocks, std::shared_ptr<Player> player);
};

