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

	bool _isInitialized;

	float calcDistanceToTargetPoint(characters::Position pos);
	void calcDirection() override;
public:
	void setStdMode();

	virtual void resetAppearance() = 0;

	void setMode(std::shared_ptr<Mode> m);

	bool isInitialized();
	void resetAll();

	void init();

	Ghost(char** blocks);
	virtual ~Ghost() {}
};

