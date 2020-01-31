#include "Die.h"

#include <fstream>
#include <iostream>
#include <time.h>

#include <ncurses.h>

id_space::SCENE_ID Die::update(sec)
{
    clear();

    bool outLoop = false;
    utilities_space::NCSupport.addSymbol("RED_BLOCK", ' ', COLOR_BLACK, COLOR_RED);

    sec start = 0.f, delta = 0.f, timer = 0.f;

    while(outLoop == false)
    {
        if(timer >= 2.f)
        {
            outLoop = true;
        }

        start = clock();


        utilities_space::NCSupport.drawRect(position_space::DIE_SCREEN_POSITION, map_space::DIE_MAP, utilities_space::NCSupport.getAppearance("RED_BLOCK"));

        delta = (clock() - start) / CLOCKS_PER_SEC;
        timer += delta;

        refresh();
    }


    return id_space::SCENE_ID::BEFORE_BIG_BANG;
}

Die::Die()
{
}
