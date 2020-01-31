#include "Clyde.h"
#include "ClydeChase.h"

void Clyde::resetPosition()
{
    _pos = position_space::CLYDE_START_POSITION;
}

void Clyde::resetAppearance()
{
    _appearance = appearance_space::CLYDE_APPREARANCE;
}

Clyde::Clyde(std::shared_ptr<Characters> player) :
    Ghost(position_space::CLYDE_START_POSITION, appearance_space::CLYDE_APPREARANCE, 0.5f)
{


	_stdMode.reset(new ClydeChase(mode::MAX_DURATION, player, this));
	_mode = _stdMode;

	_isInitialized = true;
}
