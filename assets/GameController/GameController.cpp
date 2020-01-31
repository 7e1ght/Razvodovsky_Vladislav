#include "GameController.h"
#include "Game.h"
#include "Die.h"
#include "MainMenu.h"
#include "Support.h"
#include "Lose.h"

#include <time.h>
#include <iostream>
#include <thread>
#include <chrono>
#include <ncurses.h>

void GameController::startGame()
{
    id_space::SCENE_ID currentScene = id_space::SCENE_ID::MAIN_MENU, lastScene = id_space::SCENE_ID::BEFORE_BIG_BANG;

    sec delta = 0.0f, start = 0.0f;

    bool outLoop = false;
    while (outLoop == false)
	{
        start = clock();
		
		switch (currentScene)
		{

        case id_space::SCENE_ID::MAIN_MENU:
			if (currentScene != lastScene)
			{
                _currentScene.reset(new MainMenu);
                lastScene = id_space::SCENE_ID::MAIN_MENU;
                clear();
			}
            currentScene = _currentScene->update(delta);
			break;
        case id_space::SCENE_ID::GAME:
			if (currentScene != lastScene)
			{
                _currentScene.reset(new Game);
                lastScene = id_space::SCENE_ID::GAME;
                clear();
			}
            currentScene =  _currentScene->update(delta);
			break;
        case id_space::SCENE_ID::LOSE:
			if (currentScene != lastScene)
			{
                _currentScene.reset(new Lose);
                lastScene = id_space::SCENE_ID::LOSE;
                clear();
			}

            currentScene = _currentScene->update(delta);

			break;
        case id_space::SCENE_ID::END_GAME:
            outLoop = true;
            break;

        default:
            break;
		}

        delta = (clock() - start)/CLOCKS_PER_SEC;

        refresh();
	}
}

GameController::GameController()
    : _currentScene(nullptr)
{

}
