#pragma once
#include "Mode.h"
#include "Support.h"
#include "Player.h"

#include <memory>

class BlinkyChase :
	public Mode
{
private:
    position_space::Position calcTargetPoint() override;
public:

    BlinkyChase(sec duraction);
};

