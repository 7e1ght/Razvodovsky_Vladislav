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

void GameController::startGame()
{
	scene::SCENE_ID currentScene = scene::MAIN_MENU, lastScene = scene::BEFORE_BIG_BANG;

	while (true)
	{
		_drawer->clearCanvas();
		
		switch (currentScene)
		{
		case scene::MAIN_MENU:
			if (currentScene != lastScene)
			{
				_currentScene.reset(new MainMenu(_drawer));
				lastScene = scene::MAIN_MENU;
			}
			currentScene = _currentScene->update();
			break;
		case scene::GAME:
			if (currentScene != lastScene)
			{
				_currentScene.reset(new Game(_drawer));
				lastScene = scene::GAME;
			}
			currentScene =  _currentScene->update();
			break;
		case scene::LOSE:
			if (currentScene != lastScene)
			{
				_currentScene.reset(new Lose(_drawer));
				lastScene = scene::LOSE;
			}

			currentScene = _currentScene->update();

			break;
		default:
			break;
		}
	}
}

GameController::GameController() :
	_drawer(new Drawer), _currentScene(nullptr)
{

}