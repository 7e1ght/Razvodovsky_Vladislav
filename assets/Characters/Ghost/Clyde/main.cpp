#include "Support.h"
#include "Clyde.h"

#include <chrono>
#include <iostream>

int main()
{
    utilities_space::SHMHellper::connectSHM(shm_space::playerPrefix + shm_space::positionTag);
    utilities_space::SHMHellper::connectSHM(shm_space::gameShmStateName);
    Clyde clyde;

    while(utilities_space::SHMHellper::getDataSHM<game_scene::STATE>(shm_space::gameShmStateName) != game_scene::STATE::LOSE)
    {
        clyde.move();
    }

    return 0;
}
