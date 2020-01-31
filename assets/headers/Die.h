#pragma once
#include "Scene.h"

#include "Support.h"

class Die :
	public Scene
{
private:
	char _screen[drawer::CANVAS_ROW][drawer::CANVAS_COLUMN];
public:
    id_space::SCENE_ID update(sec) override;

    Die();
};

