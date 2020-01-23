#pragma once
#include "Mode.h"
#include "Support.h"

class Scatter :
	public Mode
{
private:
	characters::Position _runTo;
public:
	characters::Position calcTargetPoint() override;

	Scatter(sec durartion, characters::Position p);
};

