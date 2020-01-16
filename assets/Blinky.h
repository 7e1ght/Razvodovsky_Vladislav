#pragma once
#include <memory>

#include "Player.h"

class Blinky :
	public Characters
{
private:
	struct PosState
	{
		Position pos;
		DIRECTION dir;

		PosState(Position p, DIRECTION d) : pos(p), dir(d)
		{

		}
	};

	Position targetPoint;
	std::shared_ptr<Player> player;
	void calcTargetPoint();
	float calcDistance(PosState ps);

	bool isLastPosition(unsigned short x, unsigned short y);

	Position lastPosition;
public:
	void move() override;

	Blinky(const char blocks[][gamefield::GAMEFIELD_COLUMN], std::shared_ptr<Player> player);
};

