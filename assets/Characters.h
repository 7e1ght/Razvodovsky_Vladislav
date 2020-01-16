#pragma once
#include "Support.h"

class Characters
{
private:	
	void fillRow(const char blocks[][gamefield::GAMEFIELD_COLUMN], int row);
	void changePosition();

	sec _moveTimer;

protected:
	sec _timer;
	char _blocks[gamefield::GAMEFIELD_ROW][gamefield::GAMEFIELD_COLUMN];

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

	void setMoveInterval(sec interval);
	drawer::ConsoleSymbolData getAppearance();

	Characters(const char blocks[][gamefield::GAMEFIELD_COLUMN]);
	virtual ~Characters() {}
};