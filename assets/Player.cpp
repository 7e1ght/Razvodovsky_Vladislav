#include "Player.h"

#include <conio.h>

inline void Player::changeDirection()
{
	using namespace characters;

	switch (_getch())
	{
	case 'W': case 'w':
		_nextDir = UP;
		break;
	case 'A': case 'a':
		_nextDir = LEFT;
		break;
	case 'S': case 's':
		_nextDir = DOWN;
		break;
	case 'D': case 'd':
		_nextDir = RIGHT;
		break;
	default:
		break;
	}

	
}

void Player::calcDirection()
{
	if (!isCollusion(_nextDir))
		_dir = _nextDir;

	if (_kbhit())
	{	
		changeDirection();	
	}
}

Player::Player(const char blocks[][gamefield::GAMEFIELD_COLUMN]) :
	Characters(blocks), _nextDir(characters::STOP)
{
	_pos = { characters::PLAYER_START_X, characters::PLAYER_START_Y };
	_appearance = characters::PLAYER_APPREARANCE;
	_dir = characters::STOP;
	_moveInterval = 0.08f;
}