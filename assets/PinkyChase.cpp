#include "PinkyChase.h"

inline characters::Position PinkyChase::calcFuturePos()
{
	using namespace characters;

	Position playerPos = _player->getPosition();

	switch (_player->getDir())
	{
	case UP:
		return { playerPos.x, playerPos.y - 4 };
	case DOWN:
		return { playerPos.x, playerPos.y + 4 };
	case LEFT:
		return { playerPos.x - 4, playerPos.y };
	case RIGHT:
		return { playerPos.x + 4, playerPos.y };
	default:
		return { -1, -1 };
	}
}

characters::Position PinkyChase::calcTargetPoint()
{
	if (_player)
	{
		return calcFuturePos();
	}
}

PinkyChase::PinkyChase(sec duraction, std::shared_ptr<Player> player) :
	Mode(duraction), _player(player)
{

}
