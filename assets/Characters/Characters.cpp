#include "Characters.h"

#include "Support.h"


position_space::Position Characters::getPosition()
{
	return _pos;
}

inline void Characters::changePosition()
{
    using dir = characters::DIRECTION;
    namespace gf = gamefield;

	switch (_dir)
	{
    case dir::UP:
		_pos.y -= 1;
		break;
    case dir::DOWN:
		_pos.y += 1;
		break;
    case dir::RIGHT:
		_pos.x += 1;
        if (_pos.x >= gf::GAMEFIELD_ROW-1) _pos.x = 0;
		break;
    case dir::LEFT:
		_pos.x -= 1;
        if (_pos.x <= 0) _pos.x = gf::GAMEFIELD_ROW - 1;
		break;
	default:
		break;
	}
}

void Characters::move()
{
    calcDirection();

    if (std::chrono::duration<float>(std::chrono::steady_clock::now() - _lastCall).count() >= _moveInterval)
    {

        if (isCollusion(_dir) == false)
        {
            _lastPosition = _pos;
            changePosition();


            setPositionToSHM();
        }
			
        _moveTimer = 0.f;

        _lastCall = std::chrono::steady_clock::now();

    }
}

characters::DIRECTION Characters::getDir()
{
	return _dir;
}

void Characters::setMoveInterval(sec interval)
{
	_moveInterval = interval;
}

appearance_space::ConsoleSymbolData Characters::getAppearance()
{
    return _appearance;
}

void Characters::setAppearance(const appearance_space::ConsoleSymbolData &appearance)
{
    _appearance = appearance;
    setAppearanceToSHM();
}

bool Characters::isCollusion(characters::DIRECTION d)
{
    using namespace characters;
    using namespace map_space;
    using namespace id_space;

	unsigned short heroX = _pos.x;
	unsigned short heroY = _pos.y;

	bool isBlock = false;

    if (UP == d && (WALL == BLOCK_MAP[heroY - 1][heroX] || DOOR == BLOCK_MAP[heroY - 1][heroX]))
		isBlock = true;
	else if (DOWN == d && (WALL == BLOCK_MAP[heroY + 1][heroX] || DOOR == BLOCK_MAP[heroY + 1][heroX]))
		isBlock = true;
	else if (LEFT == d && (WALL == BLOCK_MAP[heroY][heroX - 1] || DOOR == BLOCK_MAP[heroY][heroX - 1])) 
		isBlock = true;
	else if (RIGHT == d && (WALL == BLOCK_MAP[heroY][heroX + 1] || DOOR == BLOCK_MAP[heroY][heroX + 1])) 
		isBlock = true;

	return isBlock;
}


Characters::Characters(position_space::Position pos, appearance_space::ConsoleSymbolData a, sec interval) :
	_timer(0.0f), _moveTimer(0.0f), _pos(pos), _appearance(a), _dir(characters::STOP), _moveInterval(interval),
    _lastPosition{-1, -1}, _lastCall(std::chrono::steady_clock::now())
{
}
