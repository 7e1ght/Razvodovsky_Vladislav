#pragma once
#include "Mode.h"
#include "Player.h"
#include "Support.h"
#include "Clyde.h"

#include <memory>

class ClydeChase :
	public Mode
{
private:
	Characters* _clyde;

    position_space::Position calcTargetPoint();
    void targetPoint(position_space::Position& p);
	
	float calcDistance();
public:

    ClydeChase(sec duraction, Characters* clyde);
};

