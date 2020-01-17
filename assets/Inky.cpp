#include "Inky.h"
#include "InkyChase.h"

void Inky::resetPosition()
{
	_pos = characters::INKY_START_POSITION;
}

void Inky::resetAppearance()
{
	_appearance = characters::INKY_APPREARANCE;
}

Inky::Inky(char** blocks, std::shared_ptr<Player> player, std::shared_ptr<Blinky> blinky) :
	Ghost(blocks)
{
	_pos = characters::INKY_START_POSITION;
	_appearance = characters::INKY_APPREARANCE;
	_dir = characters::STOP;
	_moveInterval = 0.5f;

	_stdMode.reset(new InkyChase(mode::MAX_DURATION, player, blinky));
	_mode = _stdMode;

	_isInitialized = true;
}
