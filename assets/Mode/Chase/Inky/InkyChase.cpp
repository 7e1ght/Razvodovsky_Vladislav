#include "InkyChase.h"

position_space::Position InkyChase::calcTargetPoint()
{
    position_space::Position p{ -1, -1 };

	if (_player != nullptr)
	{
		targetPosition(p);
	}

	return p;
}

inline void InkyChase::targetPosition(position_space::Position& p)
{
    using namespace position_space;
    using namespace characters;

	Position pp = _player->getPosition(); // player position
	Position bp = _blinky->getPosition(); // blinky position

	switch (_player->getDir())
	{
	case UP:
		p = (bp - Position(pp.x, pp.y - 2)) * 2;
		break;
	case DOWN:
		p = (bp - Position(pp.x, pp.y + 2)) * 2;
		break;
	case LEFT:
		p = (bp - Position(pp.x - 2, pp.y)) * 2;
		break;
	case RIGHT:
		p = (bp - Position(pp.x + 2, pp.y)) * 2;
		break;
	default:
		break;
	}

}

InkyChase::InkyChase(sec duraction, std::shared_ptr<Characters> player, std::shared_ptr<Characters> blinky) :
	Mode(duraction), _player(player), _blinky(blinky)
{
}
