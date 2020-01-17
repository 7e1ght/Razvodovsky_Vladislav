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

	if (_moveTimer >= _moveInterval)
	{
		calcDirection();

		if (!isCollusion(_dir)) changePosition();

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

	if (UP == d && (WALL == _blocks[heroY - 1][heroX] || DOOR == _blocks[heroY - 1][heroX])) return true;
	else if (DOWN == d && (WALL == _blocks[heroY + 1][heroX] || DOOR == _blocks[heroY + 1][heroX])) return true;
	else if (LEFT == d && (WALL == _blocks[heroY][heroX - 1] || DOOR == _blocks[heroY][heroX - 1])) return true;
	else if (RIGHT == d && (WALL == _blocks[heroY][heroX + 1] || DOOR == _blocks[heroY][heroX + 1])) return true;

	return false;
}


Characters::Characters(char** blocks) :
	_timer(0.0f), _moveTimer(0.0f), _blocks(blocks)
{
}

Characters::~Characters()
{
	for (int i = 0; i < gamefield::GAMEFIELD_ROW; ++i)
	{
		for (int j = 0; gamefield::GAMEFIELD_COLUMN > j; ++j)
		{
			delete[] _blocks[i];
		}
	}

	delete[] _blocks;
}
