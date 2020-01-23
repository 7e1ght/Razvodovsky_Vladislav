#pragma once
#include "Support.h"

class Mode
{
protected:
	sec _modeDuration;
	sec _modeTimer;

	bool _isOver;

	virtual characters::Position calcTargetPoint() = 0;
public:
	bool isOver();
	characters::Position modeTurn(sec delta);

	virtual ~Mode() {}
	Mode(sec duration);
};

