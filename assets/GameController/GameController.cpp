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
    id_space::SCENE_ID currentScene = id_space::SCENE_ID::MAIN_MENU;
    id_space::SCENE_ID lastScene = id_space::SCENE_ID::BEFORE_BIG_BANG;

    std::chrono::steady_clock::time_point lastCall = std::chrono::steady_clock::now();
    std::chrono::duration<float> elapseTime = std::chrono::duration<float>::zero();

    bool outLoop = false;
    while (outLoop == false)
    {
		switch (currentScene)
		{

        case id_space::SCENE_ID::MAIN_MENU:
			if (currentScene != lastScene)
			{
                _currentScene.reset(new MainMenu);
                lastScene = id_space::SCENE_ID::MAIN_MENU;
                clear();
            }
			break;
        case id_space::SCENE_ID::GAME:
			if (currentScene != lastScene)
			{
                _currentScene.reset(new Game);
                lastScene = id_space::SCENE_ID::GAME;
                clear();
            }
			break;
        case id_space::SCENE_ID::LOSE:
			if (currentScene != lastScene)
			{
                _currentScene.reset(new Lose);
                lastScene = id_space::SCENE_ID::LOSE;
                clear();
            }
			break;
        case id_space::SCENE_ID::END_GAME:
            outLoop = true;
            break;

        default:
            break;
        }

        currentScene = _currentScene->update(elapseTime.count());

        refresh();

        elapseTime = std::chrono::steady_clock::now() - lastCall;
        lastCall = std::chrono::steady_clock::now();
	}
}

GameController::GameController()
    : _currentScene(nullptr)
{

}
