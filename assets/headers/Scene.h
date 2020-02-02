#pragma once
#include "Drawer.h"
#include "Support.h"

#include <memory>

class Scene
{
public:
    virtual id_space::SCENE_ID update(sec delta) = 0;
	virtual ~Scene() {}
};

