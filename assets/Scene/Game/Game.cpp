#include <iostream>
#include <fstream>
#include <string>
#include <time.h>
#include <ncurses.h>
#include <spawn.h>
#include <unistd.h>

#include "Game.h"
#include "Support.h"
#include "Scatter.h" 
#include "Initializing.h"
#include "Die.h"

using bid = id_space::BLOCK_ID;
namespace apps = appearance_space;
namespace gf = gamefield;
namespace maps = map_space;

id_space::SCENE_ID Game::update(sec delta)
{
    setStateToSHM();

    switch (_state)
    {
    case game_scene::LOSE:
        _sceneId = id_space::SCENE_ID::LOSE;
        break;
    case game_scene::WIN:
        break;
    case game_scene::PLAY:
        sceneTurn(delta);
        break;
    case game_scene::PAUSE:
        break;
    case game_scene::GHOST_EAT_ME:
        resetAll();
        dieScreen();
        _state = game_scene::STATE::PLAY;
        clear();

        break;
    case game_scene::RESET_GAME:
        break;
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

void Game::drawBlockMap(const int row, const int column)
{
    switch (map_space::BLOCK_MAP[row][column])
    {
    case bid::SPACE:
        drawSymbol(column, row+1, apps::SPACE_APPEARANCE);
        break;
    case bid::WALL:
        drawSymbol(column, row+1, apps::WALL_APPEARANCE);
        break;
    case bid::DOOR:
        drawSymbol(column, row+1, apps::DOOR_APPEARANCE);
        break;
    default:
        break;
    }
}

inline void Game::sceneTurn(sec delta)
{
    if (_mainHero == nullptr) return;

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
        drawBlockMap(row, column);
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

    position_space::Position pPos = _mainHero->getPosition();

    if (row == pPos.y
        && column == pPos.x
        )
    {
        drawSymbol(column, row+1, appearance_space::PLAYER_APPREARANCE);
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
//	for (int i = 0; i < _characters.size(); ++i)
//		_characters[i]->resetPosition();
}

inline void Game::dieScreen()
{
    Die().update(scene::NO_DELTA);
}

inline void Game::doMove(const sec delta)
{
    _mainHero->move();
}

inline void Game::checkMapEvent()
{
	using namespace game_scene;

    short heroY = _mainHero->getPosition().y;
    short heroX = _mainHero->getPosition().x;

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

    for (int i = 0; i < _characters.size(); ++i)
    {
        if (_characters[i]->getPosition().x == heroX
            && _characters[i]->getPosition().y == heroY)
        {
            --_life;
            _state = game_scene::GHOST_EAT_ME;
            if (_life == 0) _state = game_scene::LOSE;
        }
    }

}

Game::Game()
    : _score(0), _timer(0.f), _life(3), _state(game_scene::PLAY), _sceneId(id_space::SCENE_ID::GAME),
      _dieScreenTimer(0.f), pause(true),
      _blinky(new utilities_space::CharacterShmWrapper(shm_space::blinkyPrefix))
{
	using namespace game_scene;
    utilities_space::SHMHellper::createSHM(shm_space::gameShmStateName, sizeof(game_scene::STATE));
    setStateToSHM();

    resetFood();

    _mainHero = std::make_shared<Player>();

    _characters.push_back(_blinky);

    pid_t pid;
    char* argv[] = {(char*)0};
    posix_spawn(&pid, "/home/vlad/projects/qt/Razvodovsky_Vladislav/ghosts_proc/BlinkyMain", nullptr, nullptr, argv, environ);
    utilities_space::SHMHellper::connectSHM(shm_space::blinkyPrefix + shm_space::positionTag);
    utilities_space::SHMHellper::connectSHM(shm_space::blinkyPrefix + shm_space::appearanceTag);
}

