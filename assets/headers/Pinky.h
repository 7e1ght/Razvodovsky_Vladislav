#pragma once
#include "Ghost.h"
#include "Support.h"
#include "Player.h"
#include "PinkyChase.h"

class Pinky :
	public Ghost
{
public:

	void resetPosition() override;
	void resetAppearance() override;

    void setPositionToSHM() override;
    void setAppearanceToSHM() override;
    void setDirToSHM() override;

    Pinky();
};

