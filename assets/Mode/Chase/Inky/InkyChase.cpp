#include "InkyChase.h"

position_space::Position InkyChase::calcTargetPoint()
{
    position_space::Position p{ 30, 30 };

    targetPosition(p);

	return p;
}

inline void InkyChase::targetPosition(position_space::Position& p)
{
    using namespace position_space;
    using namespace characters;

    Position pp = utilities_space::SHMHellper::getDataSHM<Position>(shm_space::playerPrefix+shm_space::positionTag);
    Position bp = utilities_space::SHMHellper::getDataSHM<Position>(shm_space::blinkyPrefix+shm_space::positionTag);

    switch (utilities_space::SHMHellper::getDataSHM<characters::DIRECTION>(shm_space::playerPrefix+shm_space::dirTag))
	{
	case UP:
        p = (bp - Position(pp.x, pp.y - 2)) * 2;
		break;
	case DOWN:
        p = (bp - Position(pp.x, pp.y + 2)) * 2;
		break;
	case LEFT:
        p = (bp - Position(pp.x - 2, pp.y)) * 2;
		break;
	case RIGHT:
        p = (bp - Position(pp.x + 2, pp.y)) * 2;
		break;
	default:
		break;
	}

}

InkyChase::InkyChase(sec duraction)
    : Mode(duraction)
{
}
