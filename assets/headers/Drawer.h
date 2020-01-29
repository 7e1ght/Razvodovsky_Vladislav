#ifndef Drawer_H
#define Drawer_H

#include "Support.h"

#include <vector>
#include <ncurses.h>

class Drawer
{
private:

	drawer::ConsoleSymbolData _canvas[drawer::CANVAS_COLUMN][drawer::CANVAS_ROW];
    void setCursorPos(unsigned short x, unsigned short y);

	void outSymbolDataRow(int row);
	void setRowToZero(int row);
public:
	void clearCanvas();

	void setChar(unsigned short x, unsigned short y, const drawer::ConsoleSymbolData& apprearance);
    void setChar(char c, unsigned short x, unsigned short y, const blocks::BLOCK_ID block);
    void setText(const char* text, unsigned short x, unsigned short y);
    void setRectangle(const std::vector<std::vector<char>>& rect, const unsigned short x, const unsigned short y, const drawer::ConsoleSymbolData& style);

	void draw();

	Drawer();
};


#endif
