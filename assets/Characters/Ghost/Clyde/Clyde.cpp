#include "Clyde.h"
#include "ClydeChase.h"

void Clyde::resetPosition()
{
	_pos = characters::CLYDE_START_POSITION;
}

void Clyde::resetAppearance()
{
    _appearance = characters::CLYDE_APPEARANCE;
}

Clyde::Clyde(std::shared_ptr<Characters> player) :
    Ghost(characters::CLYDE_START_POSITION, characters::CLYDE_APPEARANCE, 0.5f)
{
	_stdMode.reset(new ClydeChase(mode::MAX_DURATION, player, this));
	_mode = _stdMode;

	_isInitialized = true;
}
