#pragma once
#include "Characters.h"
#include "Player.h" 
#include "Support.h"
#include "Ghost.h"

#include <memory>

class Blinky :
	public Ghost
{
public:

	void resetPosition() override;
	void resetAppearance() override;

    void setPositionToSHM() override;
    void setAppearanceToSHM() override;
    void setDirToSHM() override;

    Blinky();
};
