#pragma once
#include "Ghost.h"
#include "Player.h"
#include "Support.h"

#include <memory>

class Clyde :
	public Ghost
{
public:

	void resetPosition() override;
	void resetAppearance() override;

	Clyde(std::shared_ptr<Characters> player);
};

