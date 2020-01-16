#pragma once
#include "Scene.h"
#include "Player.h"
#include "Blinky.h"
#include "Pinky.h"
#include "Drawer.h"
#include "Support.h"

class Game :
	public Scene
{
private:
	sec _timer;
	unsigned _score;

	char _blocks[gamefield::GAMEFIELD_COLUMN][gamefield::GAMEFIELD_ROW];
	char _foods[gamefield::GAMEFIELD_COLUMN][gamefield::GAMEFIELD_ROW];

	std::shared_ptr<Player> _mainHero;
	std::shared_ptr<Blinky> _blinky;
	std::shared_ptr<Pinky> _pinky;
public:
	bool update(sec delta) override;

	Game(std::shared_ptr<Drawer> d);
};

