#pragma once
#include "Support.h"

#include <chrono>

class Characters
{
private:
	void changePosition();

protected:

	sec _moveTimer;
	sec _moveInterval;
	sec _timer;

    std::chrono::steady_clock::time_point _lastCall;

    position_space::Position _pos;
    position_space::Position _lastPosition;
	characters::DIRECTION _dir;

	bool isCollusion(characters::DIRECTION d);

	virtual void calcDirection() = 0;
    virtual void setPositionToSHM() = 0;
    virtual void setAppearanceToSHM() = 0;
    virtual void setDirToSHM() = 0;

    appearance_space::ConsoleSymbolData _appearance;

public:
    position_space::Position getPosition();
    void move();

	characters::DIRECTION getDir();

	virtual void resetPosition() = 0;

	void setMoveInterval(sec interval);
    appearance_space::ConsoleSymbolData getAppearance();

    void setAppearance(const appearance_space::ConsoleSymbolData& appearance);

    Characters(position_space::Position pos, appearance_space::ConsoleSymbolData a, sec interval);

	virtual ~Characters() {}
};
