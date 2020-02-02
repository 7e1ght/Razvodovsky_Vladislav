#pragma once
#include "Support.h"

class Mode
{
protected:
	sec _modeDuration;
	sec _modeTimer;

	bool _isOver;

    virtual position_space::Position calcTargetPoint() = 0;
public:
	bool isOver();
    position_space::Position modeTurn(sec delta);

	virtual ~Mode() {}
	Mode(sec duration);
};

