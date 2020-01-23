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
	std::shared_ptr<Characters> _player;
	Characters* _clyde;

	characters::Position calcTargetPoint();
	void targetPoint(characters::Position& p);
	
	float calcDistance();
public:

	ClydeChase(sec duraction, std::shared_ptr<Characters> player, Characters* clyde);
};

