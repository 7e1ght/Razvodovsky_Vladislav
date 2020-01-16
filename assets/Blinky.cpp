#include "Blinky.h"
#include <vector>
#include "Support.h"

using namespace gamefield;


void Blinky::calcTargetPoint()
{
	targetPoint.x = player->getPosition().x;
	targetPoint.y = player->getPosition().y;
}


float Blinky::calcDistance(PosState ps)
{
	return sqrt( powf(targetPoint.x - ps.pos.x, 2) + powf(targetPoint.y - ps.pos.y, 2));
}

bool Blinky::isLastPosition(unsigned short x, unsigned short y)
{
	return !(lastPosition.x != x && lastPosition.y != y);
}

void Blinky::move()
{
	calcTargetPoint();

	std::vector<PosState> ways;

	unsigned short x = pos.x, y = pos.y;
	unsigned short xLast = lastPosition.x, yLast = lastPosition.y;

	if (!isCollusion(UP) && yLast != y-1) ways.emplace_back(Position(x, y - 1), UP);
	if (!isCollusion(DOWN) && yLast != y+1) ways.emplace_back(Position(x, y + 1), DOWN);
	if (!isCollusion(RIGHT) && xLast != x+1) ways.emplace_back(Position(x + 1, y), RIGHT);
	if (!isCollusion(LEFT) && xLast != x-1) ways.emplace_back(Position(x - 1, y), LEFT);

	float minDistance = calcDistance(ways[0]);
	unsigned minDistanceIndex = 0;

	if (ways.size() > 1)
	{
		for (unsigned i = 1; i < ways.size(); i++)
		{
			if (calcDistance(ways[i]) < minDistance)
			{
				minDistance = calcDistance(ways[i]);
				minDistanceIndex = i;
			}
		}
	}

	lastPosition = pos;
	dir = ways[minDistanceIndex].dir;

	switch (dir)
	{
	case Characters::UP:
		pos.y -= speedCoef;
		break;
	case Characters::DOWN:
		pos.y += speedCoef;
		break;
	case Characters::LEFT:
		pos.x -= speedCoef;
		break;
	case Characters::RIGHT:
		pos.x += speedCoef;
		break;
	case Characters::STOP:
		break;
	default:
		break;
	}
}

Blinky::Blinky(const char blocks[][gamefield::GAMEFIELD_COLUMN], std::shared_ptr<Player> p) : Characters(blocks), player(p), lastPosition{-1, -1}
{
	pos = { 11, 9 };
	dir = STOP;
	speedCoef = 0.8;
}
