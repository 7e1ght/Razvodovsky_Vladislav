#pragma once
#include <memory>

#include "Drawer.h"
#include "Scene.h"

class GameController
{
private:
	std::unique_ptr<Drawer> _drawer;
	std::unique_ptr<Scene> _currentScene;
public:
	void startGame();

	GameController();
};

