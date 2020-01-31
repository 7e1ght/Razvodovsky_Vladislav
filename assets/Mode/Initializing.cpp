#include "Initializing.h"

position_space::Position Initializing::calcTargetPoint()
{
    return position_space::Position(13, 10);
}

Initializing::Initializing(sec duraction)
	: Mode(duraction)
{
}
