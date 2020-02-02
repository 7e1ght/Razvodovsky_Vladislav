#pragma once
#include "Ghost.h"
#include "Player.h"
#include "Blinky.h"

#include <memory>

class Inky :
	public Ghost
{
public:

	void resetPosition() override;
	void resetAppearance() override;

    void setPositionToSHM() override;
    void setAppearanceToSHM() override;
    void setDirToSHM() override;

    Inky();
};

