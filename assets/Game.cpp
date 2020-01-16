#include <iostream>
#include <fstream>
#include <string>
#include <time.h>

#include "Game.h"
#include "Support.h"
#include "Scatter.h" 

using namespace gamefield;

bool Game::update(sec delta)
{
	using namespace game_scene;

	_timer += delta;

	if (_timer > 5.f)
	{
		std::shared_ptr<Mode> b(new Scatter(20.f, characters::Position{ 30, 0 }));
		std::shared_ptr<Mode> p(new Scatter(20.f, characters::Position{ 0, 0 }));

		_blinky->setMode( b );
		_pinky->setMode( p );

		_timer = -1111111.f;
	}

	if (!(_mainHero && _drawer)) return false;

	_mainHero->move(delta);
	_blinky->move(delta);
	_pinky->move(delta);

	unsigned short heroX = _mainHero->getPosition().x;
	unsigned short heroY = _mainHero->getPosition().y;

	if (_foods[heroY][heroX] == FOOD)
	{
		_score += 5;
		_foods[heroY][heroX] = SPACE;
	}
	else if (_foods[heroY][heroX] == ENERGYZE)
	{
		_score += 15;
		_foods[heroY][heroX] = SPACE;
	}

	std::string scoreStr = "Score: " + std::to_string(_score);

	_drawer->setText(scoreStr.c_str(), 0, 0, drawer::LIGHT_GRAY, drawer::BLACK);

	for (int i = 0; i < GAMEFIELD_COLUMN; i++)
	{
		for (int j = 0; j < GAMEFIELD_ROW; j++)
		{
			if (_blocks[i][j] == SPACE || _foods[i][j] == SPACE)
				_drawer->setChar(j, i + 1, SPACE_APPEARANCE);

			if (_blocks[i][j] == WALL)
				_drawer->setChar(j, i + 1, WALL_APPREARANCE);
			else if (_blocks[i][j] == DOOR)
				_drawer->setChar(j, i + 1, DOOR_APPEARANCE);

			if (_foods[i][j] == FOOD)
				_drawer->setChar(j, i + 1, FOOD_APPEARANCE);
			else
				if (_foods[i][j] == ENERGYZE)
					_drawer->setChar(j, i + 1, ENERGYZE_APPEARANCE);

			if (i == heroY && j == heroX)
				_drawer->setChar(j, i + 1, _mainHero->getAppearance());

			if (i == _blinky->getPosition().y && j == _blinky->getPosition().x)
				_drawer->setChar(j, i + 1, _blinky->getAppearance());

			if (i == _pinky->getPosition().y && j == _pinky->getPosition().x)
				_drawer->setChar(j, i + 1, _pinky->getAppearance());
		}
	}

	return true;
}

Game::Game(std::shared_ptr<Drawer> d) : Scene(d), _score(0), _timer(0.f)
{
	using namespace game_scene;
	std::ifstream in("map.txt");

	for (int i = 0; i < GAMEFIELD_COLUMN; i++)
	{
		for (int j = 0; j < GAMEFIELD_ROW; j++)
		{
			_blocks[i][j] = SPACE;
			_foods[i][j] = SPACE;
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
					_blocks[i][j] = c;
				else
					_foods[i][j] = c;
			}
		}
	}
	else
	{
		std::cout << "map file is not open." << std::endl;
	}

	in.close();

	_mainHero = std::make_shared<Player>(_blocks);
	_blinky = std::make_shared<Blinky>(_blocks, _mainHero);
	_pinky = std::make_shared<Pinky>(_blocks, _mainHero);
}
