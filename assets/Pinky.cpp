#include "Pinky.h"

Pinky::Pinky(const char blocks[][gamefield::GAMEFIELD_COLUMN], std::shared_ptr<Player> player) : 
	Ghost(blocks)
{
	_pos = { characters::BLINKY_START_X+1, characters::BLINKY_START_Y };
	_appearance = characters::PINKY_APPREARANCE;
	_dir = characters::STOP;
	_moveInterval = 1.0f;

	_stdMode.reset(new PinkyChase(mode::MAX_DURATION, player));
	_mode = _stdMode;
}
