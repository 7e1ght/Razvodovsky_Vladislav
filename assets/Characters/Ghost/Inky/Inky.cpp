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

Inky::Inky(std::shared_ptr<Characters> player, std::shared_ptr<Characters> blinky) :
    Ghost(position_space::INKY_START_POSITION, appearance_space::INKY_APPREARANCE, 0.5f)
{
	_stdMode.reset(new InkyChase(mode::MAX_DURATION, player, blinky));
	_mode = _stdMode;

	_isInitialized = true;
}
