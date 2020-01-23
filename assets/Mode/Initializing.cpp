#include "Initializing.h"

characters::Position Initializing::calcTargetPoint()
{
	return characters::Position(13, 10);
}

Initializing::Initializing(sec duraction)
	: Mode(duraction)
{
}
