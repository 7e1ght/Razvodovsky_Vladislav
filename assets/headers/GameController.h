#ifndef GameController_H
#define GameController_H

#include "Drawer.h"
#include "Scene.h"

#include <memory>

class GameController
{
private:
	std::unique_ptr<Scene> _currentScene;
public:
	void startGame();

	GameController();
};

#endif
