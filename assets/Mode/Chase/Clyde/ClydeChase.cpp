#include "ClydeChase.h"

#include <cmath>

characters::Position ClydeChase::calcTargetPoint()
{
	characters::Position p;

	if (_player != nullptr)
	{
		targetPoint(p);
	}

	return p;
}

float ClydeChase::calcDistance()
{
	using namespace characters;
	Position pp = _player->getPosition();
	Position cp = _clyde->getPosition();

	Position difference = pp - cp;

	return sqrtf( pow(difference.x, 2) + pow(difference.y, 2) );
}

inline void ClydeChase::targetPoint(characters::Position& p)
{	
	float distance = calcDistance();

	if (distance >= 8.f) p = _player->getPosition();
	else p = mode::CLYDE_SCATTER_POSITION;
}

ClydeChase::ClydeChase(sec duraction, std::shared_ptr<Characters> player, Characters* clyde) :
	Mode(duraction), _player(player), _clyde(clyde)
{

}
