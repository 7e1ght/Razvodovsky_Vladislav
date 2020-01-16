#include "Drawer.h"
#include <iostream>

void Drawer::Drawer::setCursorPos(unsigned short x, unsigned short y)
{
	COORD pos;
	pos.X = x;
	pos.Y = y;

	SetConsoleCursorPosition(hOut, pos);
}

void Drawer::Drawer::setColor(unsigned short foreground, unsigned short background)
{
	unsigned char color = foreground | (background << 4);
	SetConsoleTextAttribute(hOut, color);
}

void Drawer::Drawer::clearCanvas()
{
	for (int i = 0; i < CANVAS_COLUMN; i++)
	{
		for (int j = 0; j < CANVAS_ROW; j++)
		{
			canvas[i][j].symbol = 0;
			canvas[i][j].foreground = 0;
			canvas[i][j].background = 0;
		}
	}
}

void Drawer::Drawer::setChar(char c, unsigned short x, unsigned short y, unsigned char foreground, unsigned char backgroud)
{
	canvas[x][y].symbol = c;
	canvas[x][y].foreground = foreground;
	canvas[x][y].background = backgroud;
}

void Drawer::Drawer::setText(const char* text, unsigned short x, unsigned short y, unsigned char foreground, unsigned char background)
{
	while (*text)
		setChar(*(text++), x++, y, foreground, background);
}

void Drawer::Drawer::draw()
{
	using namespace std;
	for (int i = 0; i < CANVAS_COLUMN; i++)
	{
		for (int j = 0; j < CANVAS_ROW; j++)
		{
			setCursorPos(i, j);

			setColor(canvas[i][j].foreground, canvas[i][j].background);
			cout << canvas[i][j].symbol;
		}
	}

	setCursorPos(0, 0);
}

Drawer::Drawer::Drawer()
{
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);

	for (int i = 0; i < CANVAS_COLUMN; i++)
	{
		for (int j = 0; j < CANVAS_ROW; j++)
		{
			canvas[i][j].symbol = 0;
			canvas[i][j].foreground = FOREGROUND_GREEN;
			canvas[i][j].background = 0;
		}
	}
}
