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

    bool outLoop = false;

    while(outLoop == false)
    {
        game_scene::STATE gameState = utilities_space::SHMHellper::getDataSHM<game_scene::STATE>(shm_space::gameShmStateName);
        switch (gameState)
        {
        case game_scene::STATE::PLAY:
            pinky.move();
            break;
        case game_scene::STATE::LOSE:
            outLoop = true;
            break;
        case game_scene::STATE::GHOST_EAT_ME:
            pinky.resetPosition();
            break;
        default:
            break;
        }
    }

    return 0;
}
