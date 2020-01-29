#include "Die.h"

#include <fstream>
#include <iostream>
#include <time.h>

scene::SCENE_ID Die::update()
{
    _drawer->clearCanvas();
    _drawer->setRectangle(gamefield::DIE_MAP, 0, 10, characters::RED_BLOCK_APPEARANCE);

	return scene::BEFORE_BIG_BANG;
}

Die::Die(std::unique_ptr<Drawer>& d) : Scene(d)
{
}
