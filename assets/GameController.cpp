#include "GameController.h"
#include "Game.h"
#include "Support.h"

#include <time.h>
#include <iostream>


void GameController::startGame()
{
	scene::SCENE_ID currentScene = scene::GAME, lastScene = scene::BEFORE_BIG_BANG;

	sec delta = 0.f, start;

	while (true)
	{
		start = clock();
		switch (currentScene)
		{
		case scene::GAME:
			if (currentScene != lastScene)
			{
				_currentScene.reset(new Game(_drawer));
				lastScene = scene::GAME;
			}
			_currentScene->update(delta);
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