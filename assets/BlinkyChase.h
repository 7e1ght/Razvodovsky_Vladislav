#pragma once
#include "Mode.h"
#include "Support.h"
#include "Player.h"

#include <memory>

class BlinkyChase :
	public Mode
{
private:
	std::shared_ptr<Player> _player;

	characters::Position calcTargetPoint();
public:

	BlinkyChase(sec duraction, std::shared_ptr<Player> player);
};

