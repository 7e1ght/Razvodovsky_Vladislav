#include "GameController.h"

#include "Player.h"
#include <ncurses.h>
#include <iostream>
#include <spawn.h>
#include <unistd.h>
#include <Game.h>

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
