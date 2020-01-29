#include "GameController.h"
#include <ncurses.h>

using namespace std;

int main()
{
    initscr();
    keypad(stdscr, TRUE);

    GameController gc;
    gc.startGame();

    endwin();


    return 0;
}
