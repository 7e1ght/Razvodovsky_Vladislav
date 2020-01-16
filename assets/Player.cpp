#include "Player.h"

#include <conio.h>

void Player::move()
{
	if (_kbhit())
	{
		char pressed = _getch();

		switch (pressed)
		{
		case 'w':
		case 'W':
			nextDir = UP;
			break;
		case 'A':
		case 'a':
			nextDir = LEFT;
			break;
		case 's':
		case 'S':
			nextDir = DOWN;
			break;
		case 'd':
		case 'D':
			nextDir = RIGHT;
			break;
		default:
			break;
		}
	}

	if (!isCollusion(nextDir))
		dir = nextDir;

	if (!isCollusion(dir))
	{
		switch (dir)
		{
		case UP:
			pos.y -= 1.f * speedCoef;
			break;
		case DOWN:
			pos.y += 1.f * speedCoef;
			break;
		case LEFT:
			pos.x -= 1.f * speedCoef;
			break;
		case RIGHT:
			pos.x += 1.f * speedCoef;
			break;
		case STOP:
			break;
		default:
			break;
		}
	}
}

Player::Player(const char blocks[][gamefield::GAMEFIELD_COLUMN]) : Characters(blocks)
{
	pos = { 12.f, 19.f };
	dir = STOP;
	speedCoef = 0.8f;
}