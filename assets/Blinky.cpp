#include "Blinky.h"
#include "BlinkyChase.h"
#include "Scatter.h"


void Blinky::resetPosition()
{
	_pos = characters::BLINKY_START_POSITION;
}

void Blinky::resetAppearance()
{
	_appearance = characters::BLINKY_APPREARANCE;
}

Blinky::Blinky(char** blocks, std::shared_ptr<Player> player) :
	Ghost(blocks)
{
	_pos = characters::BLINKY_START_POSITION;
	_appearance = characters::BLINKY_APPREARANCE;
	_dir = characters::STOP;
	_moveInterval = 0.5f;

	_stdMode.reset(new BlinkyChase(mode::MAX_DURATION, player));
	_mode = _stdMode;

	_isInitialized = true;
}