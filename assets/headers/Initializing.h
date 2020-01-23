#pragma once
#include "Mode.h"
class Initializing :
	public Mode
{
private:
	characters::Position calcTargetPoint() override;

public:
	Initializing(sec duraction);
};

