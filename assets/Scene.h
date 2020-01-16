#pragma once
#include <memory>

#include "Drawer.h"
#include "Support.h"

class Scene
{
protected:
	std::shared_ptr<Drawer> _drawer;
public:
	virtual bool update(sec delta) = 0;
	Scene(std::shared_ptr<Drawer> d);
};

