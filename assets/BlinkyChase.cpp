#include "BlinkyChase.h"

characters::Position BlinkyChase::calcTargetPoint()
{
	return _player->getPosition();
}

BlinkyChase::BlinkyChase(sec duraction, std::shared_ptr<Player> player) :
	Mode(duraction), _player(player)
{
}
