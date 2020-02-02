#include "BlinkyChase.h"
#include <ncurses.h>

position_space::Position BlinkyChase::calcTargetPoint()
{
    position_space::Position pPos = utilities_space::SHMHellper::getDataSHM<position_space::Position>(shm_space::playerPrefix + shm_space::positionTag);
    return pPos;
}

BlinkyChase::BlinkyChase(sec duraction) :
    Mode(duraction)
{
}
