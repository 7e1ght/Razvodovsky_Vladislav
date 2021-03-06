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
    id_space::SCENE_ID _sceneId;

    std::shared_ptr<Characters> _mainHero;

    std::shared_ptr<utilities_space::CharacterShmWrapper> _blinky;
    std::shared_ptr<utilities_space::CharacterShmWrapper> _clyde;
    std::shared_ptr<utilities_space::CharacterShmWrapper> _pinky;
    std::shared_ptr<utilities_space::CharacterShmWrapper> _inky;

    std::vector<std::shared_ptr<utilities_space::CharacterShmWrapper>> _characters;

	void doMove(const sec delta);

	void sceneTurn(sec delta);

	void resetFood();
	void drawFood(const int row, const int column);

    void drawBlockMap(const int row, const int column);

    void drawSymbol(unsigned x, unsigned y, appearance_space::ConsoleSymbolData apprearance);
    void drawText(const std::string& text, const int x, const int y, const appearance_space::ConsoleSymbolData& appearance = appearance_space::DEFAULT_TEXT_APPREARANCE);

    void setStateToSHM()
    {
        utilities_space::SHMHellper::setDataSHM(_state, shm_space::gameShmStateName);
    }
	// for non-nest
	void fillRow(const int row);

	void drawCharacters(const int row, const int column);

	void drawScore();
	void drawLife();

	void resetAll();

	void dieScreen();

	void checkMapEvent();

public:
    id_space::SCENE_ID update(sec delta) override;

    Game();
	~Game() {}
};

