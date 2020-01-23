#pragma once
#include "Drawer.h"
#include "Support.h"

#include <memory>

class Scene
{
protected:
	std::unique_ptr<Drawer>& _drawer;

public:
	virtual scene::SCENE_ID update() = 0;

	Scene(std::unique_ptr<Drawer>& d);
	virtual ~Scene() {}
};

