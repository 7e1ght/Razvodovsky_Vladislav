#include "Pinky.h"

void Pinky::resetPosition()
{
	_pos = characters::PINKY_START_POSITION;
}

void Pinky::resetAppearance()
{
	_appearance = characters::PINKY_APPREARANCE;
}

Pinky::Pinky(std::shared_ptr<Characters> player) :
	Ghost(characters::PINKY_START_POSITION, characters::PINKY_APPREARANCE, 0.5f)
{
	_stdMode.reset(new PinkyChase(mode::MAX_DURATION, player));
	_mode = _stdMode;

	_isInitialized = true;
}
