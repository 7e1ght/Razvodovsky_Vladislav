#include "Pinky.h"

void Pinky::resetPosition()
{
    _pos = position_space::PINKY_START_POSITION;
}

void Pinky::resetAppearance()
{
    _appearance = appearance_space::PINKY_APPREARANCE;
}

Pinky::Pinky(std::shared_ptr<Characters> player) :
    Ghost(position_space::PINKY_START_POSITION, appearance_space::PINKY_APPREARANCE, 0.5f)
{
	_stdMode.reset(new PinkyChase(mode::MAX_DURATION, player));
	_mode = _stdMode;

	_isInitialized = true;

    setPositionToSHM();
    setAppearanceToSHM();
    setDirToSHM();
}
