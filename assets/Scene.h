#pragma once
#include <memory>

#include "Drawer.h"

class Scene
{
protected:
	std::shared_ptr<Drawer::Drawer> drawer;
public:
	virtual bool init() = 0;
	Scene(std::shared_ptr<Drawer::Drawer> d);
};

