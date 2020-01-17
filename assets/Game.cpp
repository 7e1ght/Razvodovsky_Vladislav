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

scene::SCENE_ID Game::update(sec delta)
{
	readKey();


	switch (_state)
	{
	case game_scene::LOSE:
		_drawer->clearCanvas();
		_sceneId = scene::LOSE;
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

	return _sceneId;
}


void Game::readKey()
{
	//if (_kbhit() )
	//{
	//	char pressed = _getch();
	//	if (pressed == 'P' || pressed == 'p')
	//	{
	//		if (_state == game_scene::PAUSE)
	//		{
	//			_state = game_scene::PLAY;
	//		}
	//		else if(_state == game_scene::PLAY)
	//		{
	//			_state = game_scene::PAUSE;
	//		}
	//	}
	//}
}

void Game::sceneTurn(sec delta)
{
	if ((_mainHero && _drawer && _blinky && _inky) == 0) return;

	drawScore();
	drawLife();

	for (int i = 0; i < GAMEFIELD_COLUMN; ++i)
	{
		fillRow(i);
	}

	checkMapEvent();
	doMove(delta);
}

inline void Game::fillRow(const int row)
{
	for (int j = 0; GAMEFIELD_ROW > j ; ++j)
	{
		drawMap(row, j);
		drawCharacters(row, j);
	}
}

inline void Game::drawMap(const int row, const int j)
{
	using namespace game_scene;

	if (SPACE == _blocks[row][j] || SPACE == _foods[row][j])
	{
		_drawer->setChar(j, row + 1, SPACE_APPEARANCE);
	}
		

	if (_blocks[row][j] == WALL)
	{ 
		_drawer->setChar(j, row + 1, WALL_APPREARANCE);
	}
	else if(_blocks[row][j] == DOOR)
	{
		_drawer->setChar(j, row + 1, DOOR_APPEARANCE);
	}

	if (_foods[row][j] == FOOD)
	{
		_drawer->setChar(j, row + 1, FOOD_APPEARANCE);
	}
	else if(_foods[row][j] == ENERGYZE)
	{
		_drawer->setChar(j, row + 1, ENERGYZE_APPEARANCE);
	}
}

inline void Game::drawCharacters(const int row, const int j)
{
	for (int i = 0; i < _characters.size(); ++i)
	{
		if (row == _characters[i]->getPosition().y && j == _characters[i]->getPosition().x)
			_drawer->setChar(j, row + 1, _characters[i]->getAppearance());
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
	dieScreen.update(0.f);
}

inline void Game::doMove(const float delta)
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

void Game::openDoor()
{
	for (int i = DOOR_START.x; i < DOOR_START.x + DOOR_SIZE; ++i)
	{
		_blocks[DOOR_START.y][i] = game_scene::SPACE;
	}
}

void Game::closeDoor()
{
	for (int i = DOOR_START.x; i < DOOR_START.x + DOOR_SIZE; ++i)
	{
		_blocks[DOOR_START.y][i] = game_scene::DOOR;
	}
}

Game::Game(std::shared_ptr<Drawer> d) : 
	Scene(d), _score(0), _timer(0.f), _life(3), _state(game_scene::PLAY), _sceneId(scene::GAME), _dieScreenTimer(0.f), pause(true)
{
	using namespace game_scene;
	std::ifstream in("map.txt");

	_blocks = new char* [GAMEFIELD_ROW];
	for (int i = 0; i < GAMEFIELD_COLUMN; i++)
	{
		_blocks[i] = new char[GAMEFIELD_ROW];
	}

	for (int i = 0; i < GAMEFIELD_COLUMN; ++i)
	{
		for (int j = 0; j < GAMEFIELD_ROW; ++j)
		{
			_blocks[i][j] = SPACE;
			_foods[i][j] = SPACE;
		}
	}

	if (in.is_open())
	{
		for (int i = 0; i < GAMEFIELD_COLUMN; ++i)
		{
			for (int j = 0; j < GAMEFIELD_ROW; ++j)
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
	_inky = std::make_shared<Inky>(_blocks, _mainHero, _blinky);
	_clyde = std::make_shared<Clyde>(_blocks, _mainHero);

	_characters.push_back(_mainHero);

	_characters.push_back(_blinky);
	_characters.push_back(_pinky);
	_characters.push_back(_inky);
	_characters.push_back(_clyde);
}

Game::~Game()
{
	for (int i = 0; i < gamefield::GAMEFIELD_ROW; ++i)
	{
		for(int j = 0; gamefield::GAMEFIELD_COLUMN > j; ++j)
		{
			delete[] _blocks[i];
		}
	}

	delete[] _blocks;
}
