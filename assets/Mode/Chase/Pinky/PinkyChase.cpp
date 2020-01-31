#include "PinkyChase.h"

inline position_space::Position PinkyChase::calcFuturePos()
{
    using namespace position_space;
    using namespace characters;

	Position playerPos = _player->getPosition();
    Position temp;

	switch (_player->getDir())
	{
	case UP:
        temp.x = playerPos.x;
        temp.y = playerPos.y - 4;
        break;
    case DOWN:
        temp.x = playerPos.x;
        temp.y = playerPos.y + 4;
        break;
    case LEFT:
        temp.x = playerPos.x - 4;
        temp.y = playerPos.y;
        break;
    case RIGHT:
        temp.x = playerPos.x + 4;
        temp.y = playerPos.y;
        break;
	default:
        temp.x = -1;
        temp.y = -1;
        break;
	}

    return temp;
}

position_space::Position PinkyChase::calcTargetPoint()
{
	if (_player)
	{
		return calcFuturePos();
	}
}

PinkyChase::PinkyChase(sec duraction, std::shared_ptr<Characters> player) :
	Mode(duraction), _player(player)
{

}
