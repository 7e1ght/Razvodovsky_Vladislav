#pragma once
#include <memory>

#include "Drawer.h"
#include "Scene.h"

class GameController
{
private:
	std::shared_ptr<Drawer> _drawer;
	std::unique_ptr<Scene> _currentScene;
public:
	void startGame();

	GameController();
};

