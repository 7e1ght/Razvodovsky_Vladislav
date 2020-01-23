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

	Inky(std::shared_ptr<Characters> player, std::shared_ptr<Characters> blinky);
};

