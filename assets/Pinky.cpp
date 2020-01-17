#include "Pinky.h"

void Pinky::resetPosition()
{
	_pos = characters::PINKY_START_POSITION;
}

void Pinky::resetAppearance()
{
	_appearance = characters::PINKY_APPREARANCE;
}

Pinky::Pinky(char** blocks, std::shared_ptr<Player> player) :
	Ghost(blocks)
{
	_pos = characters::PINKY_START_POSITION;
	_appearance = characters::PINKY_APPREARANCE;
	_dir = characters::STOP;
	_moveInterval = 0.5f;

	_stdMode.reset(new PinkyChase(mode::MAX_DURATION, player));
	_mode = _stdMode;

	_isInitialized = true;
}
