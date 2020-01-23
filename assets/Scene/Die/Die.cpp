#include "Die.h"

#include <fstream>
#include <iostream>

scene::SCENE_ID Die::update()
{
	for (int i = 0; i < drawer::CANVAS_ROW; ++i)
	{
		for (int j = 0; j < drawer::CANVAS_COLUMN; ++j)
		{
			if (_screen[i][j] == false)
			{
				_drawer->setChar(i, j, game_scene::SPACE_APPEARANCE);
			}
			else
			{
				_drawer->setChar(0, i, j, drawer::BLACK, drawer::RED);
			}
		}
	}

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
