#include <iostream>
#include <fstream>
#include <string>
#include <time.h>
#include <conio.h>

#include "Game.h"
#include "Support.h"
#include "Scatter.h" 
#include "Initializing.h"
#include "Die.h"

using namespace gamefield;

scene::SCENE_ID Game::update()
{
	drawBlockMap();
	sec delta = 0.0f, start;

	bool outLoop = false;

	while (outLoop == false)
	{
		start = clock();

		switch (_state)
		{
		case game_scene::LOSE:
			_sceneId = scene::LOSE;
			outLoop = true;
			break;
		case game_scene::WIN:
			break;
		case game_scene::PLAY:
			sceneTurn(delta);
			break;
		case game_scene::PAUSE:
			break;
		case game_scene::GHOST_EAT_ME:
			_timer += delta;

			if (_timer >= 2.f)
			{
				_state = game_scene::PLAY;
				_drawer->clearCanvas();
				drawBlockMap();
				_timer = 0.f;
			}
			else
			{
				dieScreen();
			}

			break;
		case game_scene::RESET_GAME:
			break;
		default:
			break;
		}

		_drawer->draw();

		delta = (clock() - start) / CLOCKS_PER_SEC;
	}

	return _sceneId;
}


void Game::resetFood()
{
	for (int i = 0; i < GAMEFIELD_ROW; ++i)
	{
		for (int j = 0; j < GAMEFIELD_COLUMN; ++j)
		{
			_foods[i][j] = FOOD_MAP[i][j];
		}
	}
}

inline void Game::drawSymbol(unsigned row, unsigned column, drawer::ConsoleSymbolData apprearance)
{
	_drawer->setChar(row, column, apprearance);
}

void Game::drawBlockMap()
{
	using namespace game_scene;

	for (int i = 0; GAMEFIELD_ROW > i; ++i)
	{
		for (int j = 0; GAMEFIELD_COLUMN > j; ++j)
		{
			switch (BLOCK_MAP[i][j])
			{
			case SPACE:
				drawSymbol(i+1, j, SPACE_APPEARANCE);
				break;
			case WALL:
				drawSymbol(i+1, j, WALL_APPREARANCE);
				break;
			case DOOR:
				drawSymbol(i+1, j, DOOR_APPEARANCE);
				break;
			default:
				break;
			}
		}
	}
}

inline void Game::sceneTurn(sec delta)
{
	if ((_mainHero && _blinky && _inky) == 0) return;

	drawScore();
	drawLife();

	for (int row = 0; GAMEFIELD_ROW > row ; ++row)
	{
		fillRow(row);
	}

	checkMapEvent();
	doMove(delta);
}

inline void Game::drawFood(const int row, const int column)
{
	using namespace game_scene;

	if (FOOD == _foods[row][column])
	{
		drawSymbol(row + 1, column, FOOD_APPEARANCE);
	} 
	else if (ENERGYZE == _foods[row][column])
	{
		drawSymbol(row + 1, column, ENERGYZE_APPEARANCE);
	}
	else if (SPACE == _foods[row][column] && SPACE == BLOCK_MAP[row][column])
	{
		drawSymbol(row + 1, column, SPACE_APPEARANCE);
	}
}

inline void Game::fillRow(const int row)
{
	for (int column = 0; GAMEFIELD_COLUMN > column; ++column)
	{
		drawFood(row, column);
		drawCharacters(row, column);
	}
}

inline void Game::drawCharacters(const int row, const int column)
{
	for (int i = 0; i < _characters.size(); ++i)
	{
		if (row == _characters[i]->getPosition().y && column == _characters[i]->getPosition().x)
			drawSymbol(row + 1, column, _characters[i]->getAppearance());
	}
}

inline void Game::drawScore()
{
	std::string scoreStr = "Score: " + std::to_string(_score);
	_drawer->setText(scoreStr.c_str(), 0, 0, drawer::LIGHT_GRAY, drawer::BLACK);
}

inline void Game::drawLife() 
{
	std::string scoreStr = "Life left: " + std::to_string(_life);
	_drawer->setText(scoreStr.c_str(), 0, gamefield::GAMEFIELD_COLUMN + 1, drawer::LIGHT_GRAY, drawer::BLACK);
}

void Game::resetAll()
{
	for (int i = 0; i < _characters.size(); ++i)
		_characters[i]->resetPosition();
}

void Game::dieScreen()
{
	Die dieScreen(_drawer);
	dieScreen.update();
}

inline void Game::doMove(const sec delta)
{
	for (int i = 0; i < _characters.size(); ++i)
	{
		_characters[i]->move(delta);
	}
}

inline void Game::checkMapEvent()
{
	using namespace game_scene;

	short
		heroY = _mainHero->getPosition().y,
		heroX = _mainHero->getPosition().x;

	if ( FOOD == _foods[heroY][heroX] )
	{
		_score += 5;
		_foods[heroY][heroX] = SPACE;
	}
	else if (ENERGYZE == _foods[heroY][heroX] )
	{
		_score += 15;
		_foods[heroY][heroX] = SPACE;
	}

	for (int i = 1; i < _characters.size(); ++i)
	{
		if (_characters[i]->getPosition().x == heroX  
			&& _characters[i]->getPosition().y == heroY)
		{
			--_life;
			_state = game_scene::GHOST_EAT_ME;
			if (_life == 0) _state = game_scene::LOSE;
			resetAll();
		}
	}

}

Game::Game(std::unique_ptr<Drawer>& d) :
	Scene(d), _score(0), _timer(0.f), _life(3), _state(game_scene::PLAY), _sceneId(scene::GAME), _dieScreenTimer(0.f), pause(true)
{
	using namespace game_scene;

	resetFood();

	_mainHero = std::make_shared<Player>();
	_blinky = std::make_shared<Blinky>(_mainHero);
	_pinky = std::make_shared<Pinky>(_mainHero);
	_inky = std::make_shared<Inky>(_mainHero, _blinky);
	_clyde = std::make_shared<Clyde>(_mainHero);

	_characters.push_back(_mainHero);

	_characters.push_back(_blinky);
	_characters.push_back(_pinky);
	_characters.push_back(_inky);
	_characters.push_back(_clyde);
}

