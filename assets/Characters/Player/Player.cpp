#include "Player.h"
#include <ncurses.h>

inline void Player::changeDirection()
{
	using namespace characters;

    switch (getch())
	{
    case 'W':
    case 'w':
    case KEY_UP:
		_nextDir = UP;
		break;
    case 'A':
    case 'a':
    case KEY_LEFT:
		_nextDir = LEFT;
		break;
    case 'S':
    case 's':
    case KEY_DOWN:
		_nextDir = DOWN;
		break;
    case 'D':
    case 'd':
    case KEY_RIGHT:
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

    if (utilities_space::kbhit())
	{	
		changeDirection();	
	}
}

void Player::setPositionToSHM()
{
    utilities_space::SHMHellper::setDataSHM(getPosition(), shm_space::playerPrefix + shm_space::positionTag);
}

void Player::setAppearanceToSHM()
{
    utilities_space::SHMHellper::setDataSHM(getAppearance(), shm_space::playerPrefix + shm_space::appearanceTag);
}

void Player::setDirToSHM()
{
    utilities_space::SHMHellper::setDataSHM(getDir(), shm_space::playerPrefix + shm_space::dirTag);
}

void Player::resetPosition()
{
    _pos = position_space::PLAYER_START_POSITION;
	_dir = characters::STOP;
	_nextDir = characters::STOP;
}

Player::Player() :
    Characters(position_space::PLAYER_START_POSITION, appearance_space::PLAYER_APPREARANCE, 0.25f),
	_nextDir(characters::STOP)
{
    utilities_space::SHMHellper::createSHM(shm_space::playerPrefix + shm_space::positionTag, sizeof(position_space::Position));
    utilities_space::SHMHellper::createSHM(shm_space::playerPrefix + shm_space::appearanceTag, sizeof(appearance_space::ConsoleSymbolData));
    utilities_space::SHMHellper::createSHM(shm_space::playerPrefix + shm_space::dirTag, sizeof(characters::DIRECTION));

    setPositionToSHM();
    setAppearanceToSHM();
    setDirToSHM();
}
