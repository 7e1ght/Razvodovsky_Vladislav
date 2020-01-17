#include "Clyde.h"
#include "ClydeChase.h"

void Clyde::resetPosition()
{
	_pos = characters::CLYDE_START_POSITION;
}

void Clyde::resetAppearance()
{
	_appearance = characters::CLYDE_APPREARANCE;
}

Clyde::Clyde(char** blocks, std::shared_ptr<Player> player) :
	Ghost(blocks)
{
	_pos = characters::CLYDE_START_POSITION;
	_appearance = characters::CLYDE_APPREARANCE;
	_dir = characters::STOP;
	_moveInterval = 0.5f;

	std::shared_ptr<Clyde> c(this);

	_stdMode.reset(new ClydeChase(mode::MAX_DURATION, player, c));
	_mode = _stdMode;

	_isInitialized = true;
}
