#pragma once
#include "Support.h"

class Characters
{
private:
	void changePosition();

	sec _moveTimer;

protected:
	sec _timer;
	char** _blocks;

	drawer::ConsoleSymbolData _appearance;
	sec _moveInterval;

	characters::Position _pos;
	characters::DIRECTION _dir;

	bool isCollusion(characters::DIRECTION d);

	virtual void calcDirection() = 0;

public:
	characters::Position getPosition();
	void move(sec delta);

	characters::DIRECTION getDir();

	virtual void resetPosition() = 0;

	void setMoveInterval(sec interval);
	drawer::ConsoleSymbolData getAppearance();

	Characters(char** blocks);
	virtual ~Characters();
};