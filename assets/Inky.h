#pragma once
#include "Ghost.h"
#include "Player.h"
#include "Blinky.h"

#include <memory>

class Inky :
	public Ghost
{
public:

	void resetPosition() override;
	void resetAppearance() override;

	Inky(char** blocks, std::shared_ptr<Player> player, std::shared_ptr<Blinky> blinky);
};

