#include <iostream>
#include <fstream>
#include <string>
#include <time.h>
#include <ncurses.h>

#include "Game.h"
#include "Support.h"
#include "Scatter.h" 
#include "Initializing.h"
#include "Die.h"

using bid = id_space::BLOCK_ID;
namespace apps = appearance_space;
namespace gf = gamefield;
namespace maps = map_space;

id_space::SCENE_ID Game::update()
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
            _sceneId = id_space::SCENE_ID::LOSE;
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
                clear();
				drawBlockMap();
				_timer = 0.f;
			}
			else
			{
                clear();
				dieScreen();
			}

			break;
		case game_scene::RESET_GAME:
			break;
		default:
			break;
		}

        refresh();

		delta = (clock() - start) / CLOCKS_PER_SEC;
	}

	return _sceneId;
}


void Game::resetFood()
{
    for (int i = 0; i < gf::GAMEFIELD_ROW; ++i)
	{
        for (int j = 0; j < gf::GAMEFIELD_COLUMN; ++j)
		{
            _foods[i][j] = map_space::FOOD_MAP[i][j];
		}
	}
}

inline void Game::drawSymbol(unsigned column, unsigned row, appearance_space::ConsoleSymbolData apprearance)
{
    position_space::Position pos(column, row);
    utilities_space::NCSupport.drawChar(pos, apprearance);
}

inline void Game::drawText(const std::string& text, const int x, const int y, const appearance_space::ConsoleSymbolData& appearance)
{
    position_space::Position pos(x, y);
    utilities_space::NCSupport.drawText(text, pos, appearance);
}

void Game::drawBlockMap()
{
    for (int i = 0; gf::GAMEFIELD_ROW > i; ++i)
	{
        for (int j = 0; gf::GAMEFIELD_COLUMN > j; ++j)
		{
            switch (map_space::BLOCK_MAP[i][j])
			{
            case bid::SPACE:
                drawSymbol(j, i+1, apps::SPACE_APPEARANCE);
				break;
            case bid::WALL:
                drawSymbol(j, i+1, apps::WALL_APPEARANCE);
				break;
            case bid::DOOR:
                drawSymbol(j, i+1, apps::DOOR_APPEARANCE);
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

    for (int row = 0; gf::GAMEFIELD_ROW > row ; ++row)
	{
		fillRow(row);
	}

	checkMapEvent();
	doMove(delta);
}

inline void Game::drawFood(const int row, const int column)
{

    if (bid::FOOD == _foods[row][column])
	{
        drawSymbol(column, row + 1, apps::FOOD_APPEARANCE);
	} 
    else if (bid::ENERGYZE == _foods[row][column])
	{
        drawSymbol(column, row + 1, apps::ENERGYZE_APPEARANCE);
	}
    else if (bid::SPACE == _foods[row][column] && bid::SPACE == maps::BLOCK_MAP[row][column])
	{
        drawSymbol(column, row + 1, apps::SPACE_APPEARANCE);
	}
}

inline void Game::fillRow(const int row)
{
    for (int column = 0; gf::GAMEFIELD_COLUMN > column; ++column)
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
        {
            drawSymbol(column, row+1, _characters[i]->getAppearance());
        }
	}
}

inline void Game::drawScore()
{
	std::string scoreStr = "Score: " + std::to_string(_score);
    drawText(scoreStr, 0, 0);
}

inline void Game::drawLife() 
{
	std::string scoreStr = "Life left: " + std::to_string(_life);
    drawText(scoreStr, 0, gamefield::GAMEFIELD_COLUMN + 1);
}

void Game::resetAll()
{
	for (int i = 0; i < _characters.size(); ++i)
		_characters[i]->resetPosition();
}

void Game::dieScreen()
{
    Die dieScreen;
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

    if (bid::FOOD == _foods[heroY][heroX] )
	{
		_score += 5;
        _foods[heroY][heroX] = bid::SPACE;
	}
    else if (bid::ENERGYZE == _foods[heroY][heroX] )
	{
		_score += 15;
        _foods[heroY][heroX] = bid::SPACE;
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

Game::Game()
    : _score(0), _timer(0.f), _life(3), _state(game_scene::PLAY), _sceneId(id_space::SCENE_ID::GAME), _dieScreenTimer(0.f), pause(true)
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

