#pragma once
#include "Scene.h"
#include "Support.h"
#include "Drawer.h"

#include <memory>

class MainMenu :
	public Scene
{
private:
    id_space::SCENE_ID _returnScene;

	enum CHOOSE
	{
		START_GAME,
		QUIT
	};

	CHOOSE _currentChoose;
	void enterPressed();
public:
    id_space::SCENE_ID update(sec delta);

    MainMenu();
};

