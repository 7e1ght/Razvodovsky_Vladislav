#include "GameController.h"
#include "Game.h"
#include "Drawer.h"

#include <iostream>
#include <time.h>

void GameController::startGame()
{
	std::shared_ptr<Drawer::Drawer> drawer(new Drawer::Drawer);

	Game game(drawer);
	game.init();
}
