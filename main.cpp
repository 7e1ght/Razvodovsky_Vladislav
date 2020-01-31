#include "GameController.h"
#include <ncurses.h>

int main()
{
    initscr();
    start_color();
    utilities_space::NCSupport.initColors();
    noecho();
    keypad(stdscr, TRUE);
    curs_set(0);

    GameController gc;
    gc.startGame();

    endwin();

	return 0;
}
