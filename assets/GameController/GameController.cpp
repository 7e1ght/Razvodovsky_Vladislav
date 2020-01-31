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

	while (true)
	{
        clear();
		
		switch (currentScene)
		{
        case id_space::SCENE_ID::MAIN_MENU:
			if (currentScene != lastScene)
			{
                _currentScene.reset(new MainMenu);
                lastScene = id_space::SCENE_ID::MAIN_MENU;
			}
			currentScene = _currentScene->update();
			break;
        case id_space::SCENE_ID::GAME:
			if (currentScene != lastScene)
			{
                _currentScene.reset(new Game);
                lastScene = id_space::SCENE_ID::GAME;
			}
			currentScene =  _currentScene->update();
			break;
        case id_space::SCENE_ID::LOSE:
			if (currentScene != lastScene)
			{
                _currentScene.reset(new Lose);
                lastScene = id_space::SCENE_ID::LOSE;
			}

			currentScene = _currentScene->update();

			break;
		default:
			break;
		}
	}
}

GameController::GameController()
    : _currentScene(nullptr)
{

}
