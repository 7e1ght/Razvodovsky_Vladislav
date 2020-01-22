#pragma once
#include "Scene.h"
#include "Support.h"
#include "Drawer.h"

#include <memory>

class Lose :
	public Scene
{
private:
	scene::SCENE_ID _returnScene;
	enum CHOOSE
	{
		MAIN_MENU,
		NEW_GAME
	};

	CHOOSE _currentChoose;
	void enterPressed();
public:
	scene::SCENE_ID update();

	Lose(std::unique_ptr<Drawer>& d);
};
