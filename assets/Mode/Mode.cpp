#include "Mode.h"

bool Mode::isOver()
{
	return _isOver;
}

position_space::Position Mode::modeTurn(sec delta)
{
	_modeTimer += delta;

	if (_modeTimer >= _modeDuration)
	{
		_isOver = true;
		_modeTimer = 0.0f;	
	}

	return calcTargetPoint();
}

Mode::Mode(sec duration) :
	_modeDuration(duration), _modeTimer(0.0f), _isOver(false)
{

}
