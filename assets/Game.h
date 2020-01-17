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
	char** _blocks;
	char _foods[gamefield::GAMEFIELD_COLUMN][gamefield::GAMEFIELD_ROW];

	sec _timer;
	sec _dieScreenTimer;

	bool pause;

	unsigned _score;
	unsigned _life;

	game_scene::STATE _state;
	scene::SCENE_ID _sceneId;

	std::shared_ptr<Player> _mainHero;
	std::shared_ptr<Blinky> _blinky;
	std::shared_ptr<Pinky> _pinky;
	std::shared_ptr<Inky> _inky;
	std::shared_ptr<Clyde> _clyde;

	std::vector<std::shared_ptr<Characters>> _characters;


	void sceneTurn(sec delta);

	void readKey();

	// for non-nest
	void fillRow(const int row);

	void drawMap(const int row, const int j);
	void drawCharacters(const int row, const int j);

	void drawScore();
	void drawLife();

	void resetAll();

	void dieScreen();

	void doMove(const float delta);
	void checkMapEvent();
	
	void openDoor();
	void closeDoor();

public:
	scene::SCENE_ID update(sec delta) override;

	Game(std::shared_ptr<Drawer> d);

	~Game();
};

