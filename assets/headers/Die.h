#pragma once
#include "Scene.h"

#include "Support.h"

class Die :
	public Scene
{
public:
    id_space::SCENE_ID update(sec) override;

    Die();
};

