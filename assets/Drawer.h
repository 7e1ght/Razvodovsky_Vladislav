#pragma once
#include <Windows.h>
#include "Support.h"

class Drawer
{
private:	
	HANDLE _hOut;

	drawer::ConsoleSymbolData _canvas[drawer::CANVAS_COLUMN][drawer::CANVAS_ROW];
	void setCursorPos(unsigned short x, unsigned short y);
	void setColor(unsigned short foreground, unsigned short background);

	void outSymbolDataRow(int row);
	void setRowToZero(int row);
public:
	void clearCanvas();

	void setChar(unsigned short x, unsigned short y, drawer::ConsoleSymbolData apprearance);
	void setChar(char c, unsigned short x, unsigned short y, unsigned char foreground, unsigned char background);

	void setText(const char* text, unsigned short x, unsigned short y, unsigned char foreground, unsigned char background);

	void draw();

	Drawer();
};


