#include "Die.h"

#include <fstream>
#include <iostream>

scene::SCENE_ID Die::update(sec delta)
{

	if (_drawer == nullptr) return scene::SCENE_ERROR;

	for (int i = 0; i < drawer::CANVAS_ROW; ++i)
	{
		for (int j = 0; j < drawer::CANVAS_COLUMN; ++j)
		{
			if (_screen[i][j] == false)
			{
				_drawer->setChar(j, i, game_scene::SPACE_APPEARANCE);
			}
			else
			{
				_drawer->setChar(0, j, i, drawer::BLACK, drawer::RED);
			}
		}
	}
}

Die::Die(std::shared_ptr<Drawer> d) : Scene(d)
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
		std::cout << "Can not open file" << std::endl;
	}
}
