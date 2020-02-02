#pragma once
#include "Scene.h"
#include "Support.h"
#include "Drawer.h"

#include <memory>

class Lose :
	public Scene
{
private:
    id_space::SCENE_ID _returnScene;
	enum CHOOSE
	{
		MAIN_MENU,
		NEW_GAME
	};

	CHOOSE _currentChoose;
	void enterPressed();
public:
    id_space::SCENE_ID update(sec delta);

    Lose();
};
