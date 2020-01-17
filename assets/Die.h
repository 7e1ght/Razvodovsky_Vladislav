#pragma once
#include "Scene.h"

#include "Support.h"

class Die :
	public Scene
{
private:
	char _screen[drawer::CANVAS_ROW][drawer::CANVAS_COLUMN];
public:
	scene::SCENE_ID update(sec delta) override;

	Die(std::shared_ptr<Drawer> d);
};

