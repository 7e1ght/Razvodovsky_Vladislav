#pragma once
#include "Mode.h"
#include "Support.h"

class Scatter :
	public Mode
{
private:
    position_space::Position _runTo;
public:
    position_space::Position calcTargetPoint() override;

    Scatter(sec durartion, position_space::Position p);
};

