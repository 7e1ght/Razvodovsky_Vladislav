#pragma once
#include "Scene.h"
#include "Support.h"
#include "Drawer.h"

#include <memory>

class MainMenu :
	public Scene
{
private:
	scene::SCENE_ID _returnScene;

	enum CHOOSE
	{
		START_GAME,
		QUIT
	};

	CHOOSE _currentChoose;
	void enterPressed();
public:
	scene::SCENE_ID update();

	MainMenu(std::unique_ptr<Drawer>& d);
};

