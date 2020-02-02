#ifndef Drawer_H
#define Drawer_H

#include "Support.h"

#include <vector>

class Drawer
{
private:

    appearance_space::ConsoleSymbolData _canvas[drawer::CANVAS_COLUMN][drawer::CANVAS_ROW];
	void setCursorPos(unsigned short x, unsigned short y);
	void setColor(unsigned short foreground, unsigned short background);

	void outSymbolDataRow(int row);
	void setRowToZero(int row);
public:
	void clearCanvas();

    void setChar(unsigned short x, unsigned short y, const appearance_space::ConsoleSymbolData& apprearance);
	void setChar(char c, unsigned short x, unsigned short y, unsigned char foreground, unsigned char background);
	void setText(const char* text, unsigned short x, unsigned short y, unsigned char foreground, unsigned char background);
	void setRectangle(const std::vector<std::vector<char>>& rect, const unsigned short x, const unsigned short y, const unsigned char foreground, const unsigned char background);

	void draw();

	Drawer();
};


#endif
