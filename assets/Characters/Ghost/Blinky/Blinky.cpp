#include "Blinky.h"
#include "BlinkyChase.h"
#include "Scatter.h"


void Blinky::resetPosition()
{
    _pos = position_space::BLINKY_START_POSITION;
}

void Blinky::resetAppearance()
{
    _appearance = appearance_space::BLINKY_APPREARANCE;
}

Blinky::Blinky(std::shared_ptr<Characters> player) :
    Ghost(position_space::BLINKY_START_POSITION, appearance_space::BLINKY_APPREARANCE, 0.5f)
{
	_stdMode.reset(new BlinkyChase(mode::MAX_DURATION, player));
	_mode = _stdMode;

	_isInitialized = true;
}
