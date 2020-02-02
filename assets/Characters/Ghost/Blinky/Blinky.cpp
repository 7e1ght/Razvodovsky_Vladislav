#include "Blinky.h"
#include "BlinkyChase.h"
#include "Scatter.h"


void Blinky::resetPosition()
{
    _pos = position_space::BLINKY_START_POSITION;
}

void Blinky::resetAppearance()
{
    _appearance = appearance_space::BLINKY_APPREARANCE;
}

void Blinky::setPositionToSHM()
{
    utilities_space::SHMHellper::setDataSHM(getPosition(), shm_space::blinkyPrefix + shm_space::positionTag);
}

void Blinky::setAppearanceToSHM()
{
    utilities_space::SHMHellper::setDataSHM(getAppearance(), shm_space::blinkyPrefix + shm_space::appearanceTag);
}

void Blinky::setDirToSHM()
{
    utilities_space::SHMHellper::setDataSHM(getDir(), shm_space::blinkyPrefix + shm_space::dirTag);
}

Blinky::Blinky() :
    Ghost(position_space::BLINKY_START_POSITION, appearance_space::BLINKY_APPREARANCE, 0.5f)
{
    _stdMode.reset(new BlinkyChase(mode::MAX_DURATION));
	_mode = _stdMode;

	_isInitialized = true;

    utilities_space::SHMHellper::createSHM(shm_space::blinkyPrefix + shm_space::positionTag, sizeof(position_space::Position));
    utilities_space::SHMHellper::createSHM(shm_space::blinkyPrefix + shm_space::appearanceTag, sizeof(appearance_space::ConsoleSymbolData));
    utilities_space::SHMHellper::createSHM(shm_space::blinkyPrefix + shm_space::dirTag, sizeof(characters::DIRECTION));

    setPositionToSHM();
    setAppearanceToSHM();
    setDirToSHM();
}
