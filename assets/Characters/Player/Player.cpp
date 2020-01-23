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
	if (isCollusion(_nextDir) == false)
	{
		_dir = _nextDir;
	}

	if (_kbhit())
	{	
		changeDirection();	
	}
}

void Player::resetPosition()
{
	_pos = characters::PLAYER_START_POSITION;
	_dir = characters::STOP;
	_nextDir = characters::STOP;
}

Player::Player() :
	Characters(characters::PLAYER_START_POSITION, characters::PLAYER_APPREARANCE, 0.25f), 
	_nextDir(characters::STOP)
{
}