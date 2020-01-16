#pragma once
#include <cfloat>

typedef float sec;

namespace mode
{
	const float MAX_DURATION = FLT_MAX;
}

namespace drawer
{

const unsigned short CANVAS_ROW = 30;
const unsigned short CANVAS_COLUMN = 30;

struct ConsoleSymbolData
{
	char symbol;
	unsigned char foreground;
	unsigned char background;
};

enum ConsoleColor
{
	BLACK = 0,
	BLUE = 1,
	GREEN = 2,
	CYAN = 3,
	RED = 4,
	MAGENDA = 5,
	BROWN = 6,
	LIGHT_GRAY = 7,
	DARK_GRAY = 8,
	LIGHT_BLUE = 9,
	LIGHT_GREEN = 10,
	LIGHT_CYAN = 11,
	LIGHT_RED = 12,
	LIGHT_MAGENDA = 13,
	YELLOW = 14,
	WHITE = 15
};

}

namespace gamefield
{

const unsigned short GAMEFIELD_ROW = 25;
const unsigned short GAMEFIELD_COLUMN = 25;

}

namespace characters
{

enum DIRECTION { UP, DOWN, LEFT, RIGHT, STOP };

struct Position
{
	short x;
	short y;

	Position(short xx, short yy) : x(xx), y(yy)
	{

	}

	Position()
	{
	}
};

const short PLAYER_START_X = 12;
const short PLAYER_START_Y = 19;

const short BLINKY_START_X = 11;
const short BLINKY_START_Y = 9;

const drawer::ConsoleSymbolData PLAYER_APPREARANCE { 'C', drawer::YELLOW, drawer::BLACK };
const drawer::ConsoleSymbolData BLINKY_APPREARANCE { 'B', drawer::LIGHT_RED, drawer::BLACK };
const drawer::ConsoleSymbolData INKY_APPREARANCE { 'I', drawer::LIGHT_CYAN, drawer::BLACK };
const drawer::ConsoleSymbolData CLYDE_APPREARANCE {'D', drawer::BROWN, drawer::BLACK};
const drawer::ConsoleSymbolData PINKY_APPREARANCE {'P', drawer::LIGHT_MAGENDA, drawer::BLACK};
}

namespace scene
{

enum SCENE_ID
{
	BEFORE_BIG_BANG,
	GAME, 
	LOSE
};

}

namespace game_scene
{
	enum BLOCK_ID
	{
		SPACE,
		WALL,
		FOOD,
		ENERGYZE,
		DOOR
	};

	const drawer::ConsoleSymbolData WALL_APPREARANCE { 0, drawer::BLACK, drawer::BLUE };
	const drawer::ConsoleSymbolData FOOD_APPEARANCE { '.', drawer::YELLOW, drawer::BLACK };
	const drawer::ConsoleSymbolData ENERGYZE_APPEARANCE { 'o', drawer::YELLOW, drawer::BLACK };
	const drawer::ConsoleSymbolData DOOR_APPEARANCE { 0, drawer::BLACK, drawer::LIGHT_MAGENDA };
	const drawer::ConsoleSymbolData SPACE_APPEARANCE{ 0, drawer::BLACK, drawer::BLACK };
}