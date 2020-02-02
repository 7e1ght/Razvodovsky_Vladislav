#include "ClydeChase.h"

#include <cmath>

position_space::Position ClydeChase::calcTargetPoint()
{
    position_space::Position p;

    targetPoint(p);

	return p;
}

float ClydeChase::calcDistance()
{
    using namespace position_space;

    Position pp = utilities_space::SHMHellper::getDataSHM<position_space::Position>(shm_space::playerPrefix + shm_space::positionTag);
	Position cp = _clyde->getPosition();

	Position difference = pp - cp;

	return sqrtf( pow(difference.x, 2) + pow(difference.y, 2) );
}

inline void ClydeChase::targetPoint(position_space::Position& p)
{	
	float distance = calcDistance();

    position_space::Position pPos = utilities_space::SHMHellper::getDataSHM<position_space::Position>(shm_space::playerPrefix + shm_space::positionTag);

    if (distance >= 8.f) p = pPos;
    else p = position_space::CLYDE_SCATTER_POSITION;
}

ClydeChase::ClydeChase(sec duraction, Characters* clyde) :
    Mode(duraction), _clyde(clyde)
{

}
