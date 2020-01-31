#include "Die.h"

#include <fstream>
#include <iostream>
#include <time.h>

#include <ncurses.h>

id_space::SCENE_ID Die::update()
{
    utilities_space::NCSupport.addSymbol("RED_BLOCK", ' ', COLOR_BLACK, COLOR_RED);
    utilities_space::NCSupport.drawRect(position_space::DIE_SCREEN_POSITION, map_space::DIE_MAP, utilities_space::NCSupport.getAppearance("RED_BLOCK"));

    return id_space::SCENE_ID::BEFORE_BIG_BANG;
}

Die::Die()
{
}
