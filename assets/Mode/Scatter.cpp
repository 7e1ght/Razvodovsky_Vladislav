#include "Scatter.h"

characters::Position Scatter::calcTargetPoint()
{
	return _runTo;
}

Scatter::Scatter(sec durartion, characters::Position p) : 
	Mode(durartion), _runTo(p)
{
}
