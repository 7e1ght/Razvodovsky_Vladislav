#pragma once
#include "Scene.h"
#include "Player.h"
#include "Blinky.h"
#include "Support.h"

class Game :
	public Scene
{
private:
	float timer;
	unsigned score;

	char blocks[gamefield::GAMEFIELD_COLUMN][gamefield::GAMEFIELD_ROW];
	char foods[gamefield::GAMEFIELD_COLUMN][gamefield::GAMEFIELD_ROW];

	std::shared_ptr<Player> mainHero;
	std::shared_ptr<Blinky> blinky;
public:
	bool init() override;
	char getBlock(unsigned short x, unsigned short y);
	Game(std::shared_ptr<Drawer::Drawer> d);
};

