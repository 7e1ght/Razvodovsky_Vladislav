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

	Blinky(std::shared_ptr<Characters> player);
};

