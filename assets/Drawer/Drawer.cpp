#include "Drawer.h"

#include <iostream>

using namespace drawer;

void Drawer::setCursorPos(unsigned short x, unsigned short y)
{
	COORD pos;
	pos.X = x;
	pos.Y = y;

	SetConsoleCursorPosition(_hOut, pos);
}

void Drawer::setColor(unsigned short foreground, unsigned short background)
{
	unsigned char color = foreground | (background << 4);
	SetConsoleTextAttribute(_hOut, color);
}

inline void Drawer::setRowToZero(int row)
{
	for (int j = 0; CANVAS_ROW > j; j++)
	{
		_canvas[row][j].symbol = 0;
		_canvas[row][j].foreground = 0;
		_canvas[row][j].background = 0;
	}
}

void Drawer::clearCanvas()
{
	for (int i = 0; CANVAS_COLUMN > i; i++)
	{
		setRowToZero(i);
	}
}

void Drawer::setChar(char c, unsigned short x, unsigned short y, unsigned char foreground, unsigned char background)
{
	_canvas[y][x].symbol = c;
	_canvas[y][x].foreground = foreground;
	_canvas[y][x].background = background;
}

void Drawer::setChar(unsigned short x, unsigned short y, const ConsoleSymbolData& apprearance)
{
	_canvas[y][x].symbol = apprearance.symbol;
	_canvas[y][x].foreground = apprearance.foreground;
	_canvas[y][x].background = apprearance.background;
}

void Drawer::setText(const char* text, unsigned short x, unsigned short y, unsigned char foreground, unsigned char background)
{
	while (*text)
		setChar(*(text++), y, x++, foreground, background);
}

void Drawer::setRectangle(const std::vector<std::vector<char>>& rect, const unsigned short x, const unsigned short y, const unsigned char foreground, const unsigned char background)
{
	for(int row = 0; row < rect.size(); ++row)
	{
		for(int column = 0; column < rect[row].size(); ++column)
		{
			if(int(rect[row][column]) == 1)
			{
				setChar(0, y+row, x+column, foreground, background);
			}
		}
	}
}

inline void Drawer::outSymbolDataRow(int row)
{
	for (int j = 0; CANVAS_COLUMN > j ; ++j)
	{
		setCursorPos(row, j);

		setColor(_canvas[row][j].foreground, _canvas[row][j].background);
		std::cout << _canvas[row][j].symbol;
	}
}

void Drawer::draw()
{
	for (int i = 0; CANVAS_ROW > i ; ++i)
	{
		outSymbolDataRow(i);
	}

	setCursorPos(0, 0);
}

Drawer::Drawer() 
: _hOut(GetStdHandle(STD_OUTPUT_HANDLE))
{
	CONSOLE_FONT_INFOEX font = {};
	GetCurrentConsoleFontEx(_hOut, false, &font);
	font.dwFontSize = { 12, 16 };
	font.cbSize = sizeof(font);
	lstrcpyW(font.FaceName, L"Consolas");
	SetCurrentConsoleFontEx(_hOut, false, &font);

	COORD size;
	size.X = 50;
	size.Y = 1000;

	SetConsoleScreenBufferSize(_hOut, size);

	CONSOLE_CURSOR_INFO cursorInfo;
	cursorInfo.dwSize = 1;
	cursorInfo.bVisible = 0;
	SetConsoleCursorInfo(_hOut, &cursorInfo);

	clearCanvas();
}
