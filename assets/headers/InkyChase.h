#pragma once
#include "Mode.h"
#include "Support.h"
#include "Player.h"
#include "Blinky.h"

class InkyChase :
	public Mode
{

private:
    position_space::Position calcTargetPoint();

	// for non-nest
    void targetPosition(position_space::Position& p);
public:

    InkyChase(sec duraction);
};

