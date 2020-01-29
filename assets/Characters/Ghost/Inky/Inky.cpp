#include "Inky.h"
#include "InkyChase.h"

void Inky::resetPosition()
{
	_pos = characters::INKY_START_POSITION;
}

void Inky::resetAppearance()
{
    _appearance = characters::INKY_APPEARANCE;
}

Inky::Inky(std::shared_ptr<Characters> player, std::shared_ptr<Characters> blinky) :
    Ghost(characters::INKY_START_POSITION, characters::INKY_APPEARANCE, 0.5f)
{
	_stdMode.reset(new InkyChase(mode::MAX_DURATION, player, blinky));
	_mode = _stdMode;

	_isInitialized = true;
}
