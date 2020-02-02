#include "PinkyChase.h"

inline position_space::Position PinkyChase::calcFuturePos()
{
    using namespace position_space;
    using namespace characters;

    Position playerPos = utilities_space::SHMHellper::getDataSHM<position_space::Position>(shm_space::playerPrefix + shm_space::positionTag);
    Position temp;

    switch (utilities_space::SHMHellper::getDataSHM<characters::DIRECTION>(shm_space::playerPrefix + shm_space::dirTag))
	{
	case UP:
        temp.x = playerPos.x;
        temp.y = playerPos.y - 4;
        break;
    case DOWN:
        temp.x = playerPos.x;
        temp.y = playerPos.y + 4;
        break;
    case LEFT:
        temp.x = playerPos.x - 4;
        temp.y = playerPos.y;
        break;
    case RIGHT:
        temp.x = playerPos.x + 4;
        temp.y = playerPos.y;
        break;
	default:
        temp.x = -1;
        temp.y = -1;
        break;
	}

    return temp;
}

position_space::Position PinkyChase::calcTargetPoint()
{
    return calcFuturePos();
}

PinkyChase::PinkyChase(sec duraction) :
    Mode(duraction)
{

}
