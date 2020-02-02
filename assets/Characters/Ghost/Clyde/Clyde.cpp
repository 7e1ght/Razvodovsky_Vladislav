#include "Clyde.h"
#include "ClydeChase.h"

void Clyde::resetPosition()
{
    _pos = position_space::CLYDE_START_POSITION;
}

void Clyde::resetAppearance()
{
    _appearance = appearance_space::CLYDE_APPREARANCE;
}

void Clyde::setPositionToSHM()
{
    utilities_space::SHMHellper::setDataSHM(getPosition(), shm_space::clydePrefix + shm_space::positionTag);
}

void Clyde::setAppearanceToSHM()
{
    utilities_space::SHMHellper::setDataSHM(getAppearance(), shm_space::clydePrefix + shm_space::appearanceTag);
}

void Clyde::setDirToSHM()
{
    utilities_space::SHMHellper::setDataSHM(getDir(), shm_space::clydePrefix + shm_space::dirTag);
}

Clyde::Clyde()
    : Ghost(position_space::CLYDE_START_POSITION, appearance_space::CLYDE_APPREARANCE, 0.5f)
{
    _stdMode.reset(new ClydeChase(mode::MAX_DURATION, this));
	_mode = _stdMode;

	_isInitialized = true;

    utilities_space::SHMHellper::createSHM(shm_space::clydePrefix + shm_space::positionTag, sizeof(position_space::Position));
    utilities_space::SHMHellper::createSHM(shm_space::clydePrefix + shm_space::appearanceTag, sizeof(appearance_space::ConsoleSymbolData));
    utilities_space::SHMHellper::createSHM(shm_space::clydePrefix + shm_space::dirTag, sizeof(characters::DIRECTION));

    setPositionToSHM();
    setAppearanceToSHM();
    setDirToSHM();
}
