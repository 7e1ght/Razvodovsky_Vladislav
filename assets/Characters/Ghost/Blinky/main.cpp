#include "Support.h"
#include "Blinky.h"

#include <chrono>
#include <iostream>

int main()
{
    utilities_space::SHMHellper::connectSHM(shm_space::playerPrefix + shm_space::positionTag);
    utilities_space::SHMHellper::connectSHM(shm_space::gameShmStateName);
    Blinky blinky;

    while(utilities_space::SHMHellper::getDataSHM<game_scene::STATE>(shm_space::gameShmStateName) != game_scene::STATE::LOSE)
    {
        blinky.move();
    }

    return 0;
}
