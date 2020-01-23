#include <Windows.h>

#include "GameController.h"

using namespace std;

int main()
{
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);

	CONSOLE_FONT_INFOEX font = {};
	GetCurrentConsoleFontEx(hOut, false, &font);
	font.dwFontSize = { 12, 16 };
	font.cbSize = sizeof(font);
	lstrcpyW(font.FaceName, L"Consolas");
	SetCurrentConsoleFontEx(hOut, false, &font);

	COORD size;
	size.X = 50;
	size.Y = 1000;

	SetConsoleScreenBufferSize(hOut, size);

	CONSOLE_CURSOR_INFO cursorInfo;
	cursorInfo.dwSize = 1;
	cursorInfo.bVisible = 0;
	SetConsoleCursorInfo(hOut, &cursorInfo);

	GameController gc;
	gc.startGame();

	return 0;
}