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

    position_space::Position _pos;
    position_space::Position _lastPosition;
	characters::DIRECTION _dir;

	bool isCollusion(characters::DIRECTION d);

	virtual void calcDirection() = 0;

    appearance_space::ConsoleSymbolData _appearance;

public:
    position_space::Position getPosition();
	void move(sec delta);

	characters::DIRECTION getDir();

	virtual void resetPosition() = 0;

	void setMoveInterval(sec interval);
    appearance_space::ConsoleSymbolData getAppearance();

    Characters(position_space::Position pos, appearance_space::ConsoleSymbolData a, sec interval);

	virtual ~Characters() {}
};
