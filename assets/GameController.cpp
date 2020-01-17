#include "GameController.h"
#include "Game.h"
#include "Die.h"
#include "MainMenu.h"
#include "Support.h"
#include "Lose.h"

#include <time.h>
#include <iostream>


void GameController::startGame()
{
	scene::SCENE_ID currentScene = scene::MAIN_MENU, lastScene = scene::BEFORE_BIG_BANG;

	sec delta = 0.f, start;

	while (true)
	{
		start = clock();
		switch (currentScene)
		{
		case scene::MAIN_MENU:
			if (currentScene != lastScene)
			{
				_currentScene.reset(new MainMenu(_drawer));
				lastScene = scene::MAIN_MENU;
			}
			currentScene = _currentScene->update(delta);
			break;
		case scene::GAME:
			if (currentScene != lastScene)
			{
				_currentScene.reset(new Game(_drawer));
				lastScene = scene::GAME;
			}
			currentScene =  _currentScene->update(delta);

			break;
		case scene::LOSE:
			if (currentScene != lastScene)
			{
				_currentScene.reset(new Lose(_drawer));
				lastScene = scene::LOSE;
			}
			currentScene = _currentScene->update(delta);

			break;
		default:
			break;
		}

		_drawer->draw();
		delta = (clock() - start) / CLOCKS_PER_SEC;
	}
}

GameController::GameController() : 
	_drawer(new Drawer()), _currentScene(nullptr)
{

}