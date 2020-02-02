#include "Inky.h"
#include "InkyChase.h"

void Inky::resetPosition()
{
    _pos = position_space::INKY_START_POSITION;
}

void Inky::resetAppearance()
{
    _appearance = appearance_space::INKY_APPREARANCE;
}

void Inky::setPositionToSHM()
{
    utilities_space::SHMHellper::setDataSHM(getPosition(), shm_space::inkyPrefix + shm_space::positionTag);
}

void Inky::setAppearanceToSHM()
{
    utilities_space::SHMHellper::setDataSHM(getAppearance(), shm_space::inkyPrefix + shm_space::appearanceTag);
}

void Inky::setDirToSHM()
{
    utilities_space::SHMHellper::setDataSHM(getDir(), shm_space::inkyPrefix + shm_space::dirTag);
}

Inky::Inky() :
    Ghost(position_space::INKY_START_POSITION, appearance_space::INKY_APPREARANCE, 0.5f)
{
    _stdMode.reset(new InkyChase(mode::MAX_DURATION));
	_mode = _stdMode;

	_isInitialized = true;

    utilities_space::SHMHellper::createSHM(shm_space::inkyPrefix + shm_space::positionTag, sizeof(position_space::Position));
    utilities_space::SHMHellper::createSHM(shm_space::inkyPrefix + shm_space::appearanceTag, sizeof(appearance_space::ConsoleSymbolData));
    utilities_space::SHMHellper::createSHM(shm_space::inkyPrefix + shm_space::dirTag, sizeof(characters::DIRECTION));

    setPositionToSHM();
    setAppearanceToSHM();
    setDirToSHM();
}
