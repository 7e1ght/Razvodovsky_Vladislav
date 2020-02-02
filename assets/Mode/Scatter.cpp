#include "Scatter.h"

position_space::Position Scatter::calcTargetPoint()
{
	return _runTo;
}

Scatter::Scatter(sec durartion, position_space::Position p) :
	Mode(durartion), _runTo(p)
{
}
