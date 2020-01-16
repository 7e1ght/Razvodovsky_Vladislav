#pragma once
#include <Windows.h>

namespace Drawer
{

const unsigned short CANVAS_ROW = 30;
const unsigned short CANVAS_COLUMN = 30;

enum ConsoleColor
{
	Black = 0,
	Blue = 1,
	Green = 2,
	Cyan = 3,
	Red = 4,
	Magenta = 5,
	Brown = 6,
	LightGray = 7,
	DarkGray = 8,
	LightBlue = 9,
	LightGreen = 10,
	LightCyan = 11,
	LightRed = 12,
	LightMagenta = 13,
	Yellow = 14,
	White = 15
};

struct ConsoleSymbolData
{
	char symbol;
	unsigned char foreground;
	unsigned char background;
};

class Drawer
{
private:
	HANDLE hOut;

	ConsoleSymbolData canvas[CANVAS_COLUMN][CANVAS_ROW];
	void setCursorPos(unsigned short x, unsigned short y);
	void setColor(unsigned short foreground, unsigned short background);
public:
	void clearCanvas();
	void setChar(char c, unsigned short x, unsigned short y, unsigned char foreground, unsigned char background);
	void setText(const char* text, unsigned short x, unsigned short y, unsigned char foreground, unsigned char background);
	void draw();

	Drawer();
};

}

