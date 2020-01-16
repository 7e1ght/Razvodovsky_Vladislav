#pragma once

#include "Support.h"
#include "Mode.h"
#include "Player.h"

#include <memory>

class PinkyChase :
	public Mode
{
private:
	std::shared_ptr<Player> _player;

	characters::Position calcFuturePos();

	characters::Position calcTargetPoint();
public:

	PinkyChase(sec duraction, std::shared_ptr<Player> player);
};

