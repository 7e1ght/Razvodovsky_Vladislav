#include "Characters.h"
#include <conio.h>
#include "Support.h"

using namespace gamefield;
using namespace characters;

Position Characters::getPosition()
{
	return _pos;
}

inline void Characters::changePosition()
{
	switch (_dir)
	{
	case UP:
		_pos.y -= 1;
		break;
	case DOWN:
		_pos.y += 1;
		break;
	case RIGHT:
		_pos.x += 1;
		if (_pos.x >= GAMEFIELD_ROW-1) _pos.x = 0;
		break;
	case LEFT:
		_pos.x -= 1;
		if (_pos.x <= 0) _pos.x = GAMEFIELD_ROW - 1;
		break;
	default:
		break;
	}
}

void Characters::move(sec delta)
{
	_timer += delta;

	_moveTimer += delta;

	calcDirection();

	if (_moveTimer >= _moveInterval)
	{

		if (isCollusion(_dir) == false) 
		{ 
			_lastPosition = _pos;
			changePosition();
		}
			

		_moveTimer = 0.f;
	}	
}

characters::DIRECTION Characters::getDir()
{
	return _dir;
}

void Characters::setMoveInterval(sec interval)
{
	_moveInterval = interval;
}

drawer::ConsoleSymbolData Characters::getAppearance()
{
	return _appearance;
}

bool Characters::isCollusion(DIRECTION d)
{
	using namespace game_scene;

	unsigned short heroX = _pos.x;
	unsigned short heroY = _pos.y;

	bool isBlock = false;

	if (UP == d && (WALL == BLOCK_MAP[heroY - 1][heroX] || DOOR == BLOCK_MAP[heroY - 1][heroX])) 
		isBlock = true;
	else if (DOWN == d && (WALL == BLOCK_MAP[heroY + 1][heroX] || DOOR == BLOCK_MAP[heroY + 1][heroX]))
		isBlock = true;
	else if (LEFT == d && (WALL == BLOCK_MAP[heroY][heroX - 1] || DOOR == BLOCK_MAP[heroY][heroX - 1])) 
		isBlock = true;
	else if (RIGHT == d && (WALL == BLOCK_MAP[heroY][heroX + 1] || DOOR == BLOCK_MAP[heroY][heroX + 1])) 
		isBlock = true;

	return isBlock;
}


Characters::Characters(characters::Position pos, drawer::ConsoleSymbolData a, sec interval) : 
	_timer(0.0f), _moveTimer(0.0f), _pos(pos), _appearance(a), _dir(characters::STOP), _moveInterval(interval),
	_lastPosition{-1, -1}
{
}
