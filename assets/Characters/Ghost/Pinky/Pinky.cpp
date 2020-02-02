#include "Pinky.h"

void Pinky::resetPosition()
{
    _pos = position_space::PINKY_START_POSITION;
}

void Pinky::resetAppearance()
{
    _appearance = appearance_space::PINKY_APPREARANCE;
}

void Pinky::setPositionToSHM()
{
    utilities_space::SHMHellper::setDataSHM(getPosition(), shm_space::pinkyPrefix + shm_space::positionTag);
}

void Pinky::setAppearanceToSHM()
{
    utilities_space::SHMHellper::setDataSHM(getAppearance(), shm_space::pinkyPrefix + shm_space::appearanceTag);
}

void Pinky::setDirToSHM()
{
    utilities_space::SHMHellper::setDataSHM(getDir(), shm_space::pinkyPrefix + shm_space::dirTag);
}

Pinky::Pinky() :
    Ghost(position_space::PINKY_START_POSITION, appearance_space::PINKY_APPREARANCE, 0.5f)
{
    _stdMode.reset(new PinkyChase(mode::MAX_DURATION));
	_mode = _stdMode;

	_isInitialized = true;

    utilities_space::SHMHellper::createSHM(shm_space::pinkyPrefix + shm_space::positionTag, sizeof(position_space::Position));
    utilities_space::SHMHellper::createSHM(shm_space::pinkyPrefix + shm_space::appearanceTag, sizeof(appearance_space::ConsoleSymbolData));
    utilities_space::SHMHellper::createSHM(shm_space::pinkyPrefix + shm_space::dirTag, sizeof(characters::DIRECTION));

    setPositionToSHM();
    setAppearanceToSHM();
    setDirToSHM();
}
