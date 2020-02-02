#pragma once

#include "Support.h"
#include "Mode.h"
#include "Player.h"

#include <memory>

class PinkyChase :
	public Mode
{
private:
    position_space::Position calcFuturePos();

    position_space::Position calcTargetPoint();
public:

    PinkyChase(sec duraction);
};

