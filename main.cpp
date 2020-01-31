#include "GameController.h"

#include <ncurses.h>
#include <Support.h>

using namespace std;

//inline void drawSymbol(unsigned row, unsigned column, drawer::ConsoleSymbolData apprearance)
//{
//    utilities::drawChar(row, column, apprearance);
//}

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

//    using namespace game_scene;
//    using namespace gamefield;

//    for (int i = 0; GAMEFIELD_ROW > i; ++i)
//    {
//        for (int j = 0; GAMEFIELD_COLUMN > j; ++j)
//        {
//            switch (BLOCK_MAP[i][j])
//            {
//            case SPACE:
//                drawSymbol(j, i+1, SPACE_APPEARANCE);
//                break;
//            case WALL:
//                drawSymbol(j, i+1, WALL_APPREARANCE);
//                break;
//            case DOOR:
//                drawSymbol(j, i+1, DOOR_APPEARANCE);
//                break;
//            default:
//                break;
//            }
//        }
//    }

    getch();
    endwin();

	return 0;
}
