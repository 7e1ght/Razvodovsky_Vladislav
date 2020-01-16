#pragma once
#include "Support.h"

struct Position
{
	float x;
	float y;

	Position(float xx, float yy) : x(xx), y(yy)
	{

	}

	Position()
	{

	}
};

class Characters
{
protected:
	enum DIRECTION { UP, DOWN, LEFT, RIGHT, STOP };

	char blocks[gamefield::GAMEFIELD_ROW][gamefield::GAMEFIELD_COLUMN];
	Position pos;

	DIRECTION dir;

	float speedCoef;

	bool isCollusion(DIRECTION d);
public:
	Position getPosition();
	virtual void move() = 0;

	void setSpeedCoef(unsigned short coef);

	Characters(const char blocks[][gamefield::GAMEFIELD_COLUMN]);
};