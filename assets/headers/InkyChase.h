#pragma once
#include "Mode.h"
#include "Support.h"
#include "Player.h"
#include "Blinky.h"

class InkyChase :
	public Mode
{

private:
	std::shared_ptr<Characters> _player;
	std::shared_ptr<Characters> _blinky;

	characters::Position calcTargetPoint();

	// for non-nest
	void targetPosition(characters::Position& p);
public:

	InkyChase(sec duraction, std::shared_ptr<Characters> player, std::shared_ptr<Characters> blinky);
};

