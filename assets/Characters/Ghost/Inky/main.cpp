#include "Support.h"
#include "Inky.h"

#include <chrono>
#include <iostream>

int main()
{
    utilities_space::SHMHellper::connectSHM(shm_space::playerPrefix + shm_space::positionTag);
    utilities_space::SHMHellper::connectSHM(shm_space::playerPrefix + shm_space::dirTag);
    utilities_space::SHMHellper::connectSHM(shm_space::blinkyPrefix + shm_space::positionTag);
    utilities_space::SHMHellper::connectSHM(shm_space::gameShmStateName);

    Inky inky;

    while(utilities_space::SHMHellper::getDataSHM<game_scene::STATE>(shm_space::gameShmStateName) != game_scene::STATE::LOSE)
    {
        inky.move();
    }

    return 0;
}
