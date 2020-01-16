#pragma once
#include "Characters.h"
#include "Mode.h"

#include <memory>

class Ghost :
	public Characters
{
protected:
	std::shared_ptr<Mode> _stdMode;
	std::shared_ptr<Mode> _mode;

	characters::Position _targetPoint;
	characters::Position _lastPosition;

	sec _lastCall;

	float calcDistanceToTargetPoint(characters::Position pos);
	void calcDirection() override;
public:
	void setMode(std::shared_ptr<Mode> mode);

	Ghost(const char blocks[][gamefield::GAMEFIELD_COLUMN]);
};

