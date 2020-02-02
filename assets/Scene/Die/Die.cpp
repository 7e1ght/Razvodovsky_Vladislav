#include "Die.h"

#include <chrono>

id_space::SCENE_ID Die::update(sec)
{
    clear();

    utilities_space::NCSupport.addSymbol("RED_BLOCK", ' ', COLOR_BLACK, COLOR_RED);

    std::chrono::steady_clock::time_point lastCall = std::chrono::steady_clock::now();

    while(std::chrono::steady_clock::now() - lastCall < std::chrono::seconds(2))
    {
        utilities_space::NCSupport.drawRect(position_space::DIE_SCREEN_POSITION, map_space::DIE_MAP, utilities_space::NCSupport.getAppearance("RED_BLOCK"));

        refresh();
    }


    return id_space::SCENE_ID::BEFORE_BIG_BANG;
}

Die::Die()
{
}
