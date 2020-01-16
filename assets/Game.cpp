#include <iostream>
#include <fstream>
#include <string>
#include <time.h>

#include "Game.h"

using namespace gamefield;

bool Game::init()
{
	clock_t start = clock();
	float  time = 0.f;

	while (true)
	{
		mainHero->move();
		blinky->move();

		unsigned short heroX = mainHero->getPosition().x;
		unsigned short heroY = mainHero->getPosition().y;

		if (foods[heroY][heroX] == FOOD)
		{
			score += 5;
			foods[heroY][heroX] = SPACE;
		}
		else if (foods[heroY][heroX] == ENERGYZE)
		{
			score += 15;
			foods[heroY][heroX] = SPACE;
		}

		std::string scoreStr = "Score: " + std::to_string(score);

		drawer->setText(scoreStr.c_str(), 0, 0, Drawer::LightGray, Drawer::Black);

		for (int i = 0; i < GAMEFIELD_COLUMN; i++)
		{
			for (int j = 0; j < GAMEFIELD_ROW; j++)
			{
				if (blocks[i][j] == SPACE || foods[i][j] == SPACE)
					drawer->setChar(0, j, i + 1, Drawer::Black, Drawer::Black);

				if (blocks[i][j] == WALL)
					drawer->setChar(0, j, i + 1, Drawer::Black, Drawer::Blue);
				else if (blocks[i][j] == DOOR)
					drawer->setChar(0, j, i + 1, Drawer::Black, Drawer::LightMagenta);

				if (foods[i][j] == FOOD)
					drawer->setChar('.', j, i + 1, Drawer::Yellow, Drawer::Black);
				else if (foods[i][j] == ENERGYZE)
					drawer->setChar('o', j, i + 1, Drawer::Yellow, Drawer::Black);

				if (i == heroY && j == heroX)
					drawer->setChar('C', j, i + 1, Drawer::Yellow, Drawer::Black);

				if (i == (short)blinky->getPosition().y && j == (short)blinky->getPosition().x)
					drawer->setChar('B', j, i + 1, Drawer::Red, Drawer::Black);
			}
		}

		drawer->draw();

		time = float(clock() - start) / CLOCKS_PER_SEC;
		start = clock();
	}

	return true;
}

char Game::getBlock(unsigned short x, unsigned short y)
{
	return blocks[x][y];
}

Game::Game(std::shared_ptr<Drawer::Drawer> d) : Scene(d), score(0), timer(0.f)
{
	std::ifstream in("map.txt");

	for (int i = 0; i < GAMEFIELD_COLUMN; i++)
	{
		for (int j = 0; j < GAMEFIELD_ROW; j++)
		{
			blocks[i][j] = SPACE;
			foods[i][j] = SPACE;
		}
	}

	if (in.is_open())
	{
		for (int i = 0; i < GAMEFIELD_COLUMN; i++)
		{
			for (int j = 0; j < GAMEFIELD_ROW; j++)
			{
				unsigned short c;
				in >> c;
				if (c == WALL || c == DOOR || c == SPACE)
					blocks[i][j] = c;
				else
					foods[i][j] = c;
			}
		}
	}
	else
	{
		std::cout << "map file is not open." << std::endl;
	}

	in.close();

	mainHero = std::make_shared<Player>(blocks);
	blinky = std::make_shared<Blinky>(blocks, mainHero);
}
