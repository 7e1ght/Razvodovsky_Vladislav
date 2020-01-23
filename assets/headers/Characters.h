#pragma once
#include "Support.h"

class Characters
{
private:
	void changePosition();

protected:

	sec _moveTimer;
	sec _moveInterval;
	sec _timer;

	characters::Position _pos;
	characters::Position _lastPosition;
	characters::DIRECTION _dir;

	bool isCollusion(characters::DIRECTION d);

	virtual void calcDirection() = 0;

	drawer::ConsoleSymbolData _appearance;

public:
	characters::Position getPosition();
	void move(sec delta);

	characters::DIRECTION getDir();

	virtual void resetPosition() = 0;

	void setMoveInterval(sec interval);
	drawer::ConsoleSymbolData getAppearance();

	Characters(characters::Position pos, drawer::ConsoleSymbolData a, sec interval);

	virtual ~Characters() {}
};