#include "Support.h"
#include "Pinky.h"

#include <chrono>
#include <iostream>

int main()
{
    utilities_space::SHMHellper::connectSHM(shm_space::playerPrefix + shm_space::positionTag);
    utilities_space::SHMHellper::connectSHM(shm_space::playerPrefix + shm_space::dirTag);
    utilities_space::SHMHellper::connectSHM(shm_space::gameShmStateName);

    Pinky pinky;

    while(utilities_space::SHMHellper::getDataSHM<game_scene::STATE>(shm_space::gameShmStateName) != game_scene::STATE::LOSE)
    {
        pinky.move();
    }

    return 0;
}
