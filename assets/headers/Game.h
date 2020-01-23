#pragma once
#include "Scene.h"
#include "Player.h"
#include "Blinky.h"
#include "Pinky.h"
#include "Drawer.h"
#include "Inky.h"
#include "Clyde.h"
#include "Support.h"

#include <vector>

class Game :
	public Scene
{
private:
	char _foods[gamefield::GAMEFIELD_COLUMN][gamefield::GAMEFIELD_ROW];

	sec _timer;
	sec _dieScreenTimer;

	bool pause;

	unsigned _score;
	unsigned _life;

	game_scene::STATE _state;
	scene::SCENE_ID _sceneId;

	std::shared_ptr<Characters> _mainHero;
	std::shared_ptr<Characters> _blinky;
	std::shared_ptr<Characters> _pinky;
	std::shared_ptr<Characters> _inky;
	std::shared_ptr<Characters> _clyde;

	std::vector<std::shared_ptr<Characters>> _characters;

	void doMove(const sec delta);

	void sceneTurn(sec delta);

	void resetFood();
	void drawFood(const int row, const int column);

	void drawBlockMap();

	void drawSymbol(unsigned x, unsigned y, drawer::ConsoleSymbolData apprearance);

	// for non-nest
	void fillRow(const int row);

	void drawCharacters(const int row, const int column);

	void drawScore();
	void drawLife();

	void resetAll();

	void dieScreen();

	void checkMapEvent();

public:
	scene::SCENE_ID update() override;

	Game(std::unique_ptr<Drawer>& d);
	~Game() {}
};

