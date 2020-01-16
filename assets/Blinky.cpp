#include "Blinky.h"
#include "BlinkyChase.h"

Blinky::Blinky(const char blocks[][gamefield::GAMEFIELD_COLUMN], std::shared_ptr<Player> player) :
	Ghost(blocks)
{
	_pos = { characters::BLINKY_START_X, characters::BLINKY_START_Y };
	_appearance = characters::BLINKY_APPREARANCE;
	_dir = characters::STOP;
	_moveInterval = 1.0f;

	_stdMode.reset(new BlinkyChase(mode::MAX_DURATION, player));
	_mode = _stdMode;
}