#include "BlinkyChase.h"

position_space::Position BlinkyChase::calcTargetPoint()
{
	return _player->getPosition();
}

BlinkyChase::BlinkyChase(sec duraction, std::shared_ptr<Characters> player) :
	Mode(duraction), _player(player)
{
}
