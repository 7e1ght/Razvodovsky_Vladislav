#include "Die.h"

#include <fstream>
#include <iostream>
#include <time.h>

scene::SCENE_ID Die::update()
{

	_drawer->clearCanvas();
	_drawer->setRectangle(gamefield::DIE_MAP, 0, 10, drawer::BLACK, drawer::RED);

	return scene::BEFORE_BIG_BANG;
}

Die::Die(std::unique_ptr<Drawer>& d) : Scene(d)
{
	std::ifstream in("die.txt");

	if (in.is_open())
	{
		for (int i = 0; i < drawer::CANVAS_ROW; ++i)
		{
			for (int j = 0; j < drawer::CANVAS_COLUMN; ++j)
			{
				int c;
				in >> c;
				_screen[i][j] = c;
			}
		}
	}
	else
	{
		std::cerr << "Can not open file" << std::endl;
	}
}
