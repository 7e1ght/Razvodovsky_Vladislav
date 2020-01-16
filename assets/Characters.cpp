#include "Characters.h"
#include <conio.h>
#include "Support.h"

using namespace gamefield;

Position Characters::getPosition()
{
	return this->pos;
}

void Characters::setSpeedCoef(unsigned short coef)
{
	speedCoef = coef;
}

bool Characters::isCollusion(DIRECTION d)
{
	unsigned short heroX = pos.x;
	unsigned short heroY = pos.y;

	switch (d)
	{
	case UP:
		if (blocks[heroY - 1][heroX] == WALL || blocks[heroY - 1][heroX] == DOOR) return true;
		break;
	case DOWN:
		if (blocks[heroY + 1][heroX] == WALL || blocks[heroY + 1][heroX] == DOOR) return true;
		break;
	case LEFT:
		if (blocks[heroY][heroX-1] == WALL || blocks[heroY][heroX-1] == DOOR) return true;
		break;
	case RIGHT:
		if (blocks[heroY][heroX + 1] == WALL || blocks[heroY][heroX+1] == DOOR) return true;
		break;
	case STOP:
		break;
	default:
		break;
	}

	//switch (d)
	//{
	//case UP:
	//	if (game->getBlock(heroY - 1, heroX) == WALL || game->getBlock(heroY - 1, heroX) == DOOR) return true;
	//	break;
	//case DOWN:
	//	if (game->getBlock(heroY + 1, heroX) == WALL || game->getBlock(heroY + 1, heroX) == DOOR) return true;
	//	break;
	//case LEFT:
	//	if (game->getBlock(heroY, heroX - 1) == WALL || game->getBlock(heroY, heroX - 1) == DOOR) return true;
	//	break;
	//case RIGHT:
	//	if (game->getBlock(heroY, heroX + 1) == WALL || game->getBlock(heroY, heroX + 1) == DOOR) return true;
	//	break;
	//case STOP:
	//	break;
	//default:
	//	break;
	//}
	//return false;

	return false;
}

Characters::Characters(const char blocks[][gamefield::GAMEFIELD_COLUMN])
{
	for (int i = 0; i < gamefield::GAMEFIELD_ROW; i++)
	{
		for (int j = 0; j < gamefield::GAMEFIELD_COLUMN; j++)
		{
			this->blocks[i][j] = blocks[i][j];
		}
	}
}