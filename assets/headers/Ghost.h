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

    position_space::Position _targetPoint;

	sec _lastCall;

	bool _isInitialized;

    float calcDistanceToTargetPoint(position_space::Position pos);
	void calcDirection() override;
public:
	void setStdMode();

	virtual void resetAppearance() = 0;

	void setMode(std::shared_ptr<Mode> m);

	bool isInitialized();
	void resetAll();

	void init();

    Ghost(position_space::Position pos, appearance_space::ConsoleSymbolData a, sec interval);
	virtual ~Ghost() {}
};

