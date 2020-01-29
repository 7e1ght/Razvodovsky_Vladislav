#include "Drawer.h"

#include <ncurses.h>
#include <iostream>

using namespace drawer;

void Drawer::setCursorPos(unsigned short x, unsigned short y)
{
    move(y, x);
}

inline void Drawer::setRowToZero(int row)
{
	for (int j = 0; CANVAS_ROW > j; j++)
	{
		_canvas[row][j].symbol = 0;
        _canvas[row][j].blockID = blocks::NOTHING;
	}
}

void Drawer::clearCanvas()
{
    for (int i = 0; CANVAS_COLUMN > i; i++)
    {
        setRowToZero(i);
    }
}

void Drawer::setChar(char c, unsigned short x, unsigned short y, const blocks::BLOCK_ID block)
{
	_canvas[y][x].symbol = c;
    _canvas[y][x].blockID = block;
}

void Drawer::setChar(unsigned short x, unsigned short y, const ConsoleSymbolData& apprearance)
{
	_canvas[y][x].symbol = apprearance.symbol;
    _canvas[y][x].blockID = apprearance.blockID;
}

void Drawer::setText(const char* text, unsigned short x, unsigned short y)
{
	while (*text)
        setChar(*(text++), y, x++, blocks::TEXT);
}

inline void Drawer::outSymbolDataRow(int row)
{
	for (int j = 0; CANVAS_COLUMN > j ; ++j)
	{
		setCursorPos(row, j);

        attron(COLOR_PAIR(_canvas[row][j].blockID));
        addch(_canvas[row][j].symbol);
        attroff(COLOR_PAIR(_canvas[row][j].blockID));
	}
}

void Drawer::draw()
{
	for (int i = 0; CANVAS_ROW > i ; ++i)
	{
		outSymbolDataRow(i);
	}

	setCursorPos(0, 0);
    refresh();
}

void Drawer::setRectangle(const std::vector<std::vector<char>>& rect, const unsigned short x, const unsigned short y, const ConsoleSymbolData& style)
{
    for(int row = 0; row < rect.size(); ++row)
    {
        for(int column = 0; column < rect[row].size(); ++column)
        {
            if(int(rect[row][column]) == 1)
            {
                setChar(y+row, x+column, style);
            }
        }
    }
}

Drawer::Drawer()
{
    curs_set(0);

    start_color();
    init_pair(blocks::WALL, COLOR_BLUE, COLOR_BLUE);
    init_pair(blocks::FOOD, COLOR_YELLOW, COLOR_BLACK);
    init_pair(blocks::ENERGYZE, COLOR_YELLOW, COLOR_BLACK);
    init_pair(blocks::DOOR, COLOR_BLACK, COLOR_MAGENTA);
    init_pair(blocks::SPACE, COLOR_BLACK, COLOR_BLACK);

    init_pair(blocks::BLINKY, COLOR_RED, COLOR_BLACK);
    init_pair(blocks::PINKY, COLOR_MAGENTA, COLOR_BLACK);
    init_pair(blocks::INKY, COLOR_CYAN, COLOR_BLACK);
    init_pair(blocks::CLYDE, COLOR_YELLOW, COLOR_BLACK);
    init_pair(blocks::PLAYER, COLOR_YELLOW, COLOR_BLACK);

    init_pair(blocks::TEXT, COLOR_WHITE, COLOR_BLACK);
    init_pair(blocks::RED_BLOCK, COLOR_RED, COLOR_RED);

	clearCanvas();
}
