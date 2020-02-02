#pragma once
#include "Mode.h"
class Initializing :
	public Mode
{
private:
    position_space::Position calcTargetPoint() override;

public:
	Initializing(sec duraction);
};

