#include "Ghost.h"

float Ghost::calcDistanceToTargetPoint(characters::Position pos)
{
	return sqrtf(pow(_targetPoint.x - pos.x, 2) + pow(_targetPoint.y - pos.y, 2));
}

void Ghost::calcDirection()
{
	if (_isInitialized)
	{
		if (_mode && _mode->isOver()) _mode = _stdMode;
		if (_mode)
		{
			_targetPoint = _mode->modeTurn(_timer - _lastCall);
			_lastCall = _timer;
		}

		float minDistance = 100000.f;
		characters::DIRECTION minDistanceDirection = characters::STOP;

		if (
			!isCollusion(characters::UP)
			&& (_pos.y - 1 != _lastPosition.y)
			&& calcDistanceToTargetPoint({ _pos.x, _pos.y - 1 }) < minDistance
			)
		{
			minDistance = calcDistanceToTargetPoint({ _pos.x, _pos.y - 1 });
			minDistanceDirection = characters::UP;
		}

		if (
			!isCollusion(characters::DOWN)
			&& (_pos.y + 1 != _lastPosition.y)
			&& calcDistanceToTargetPoint({ _pos.x, _pos.y + 1 }) < minDistance
			)
		{
			minDistance = calcDistanceToTargetPoint({ _pos.x, _pos.y + 1 });
			minDistanceDirection = characters::DOWN;
		}

		if (
			!isCollusion(characters::RIGHT)
			&& (_pos.x + 1 != _lastPosition.x)
			&& calcDistanceToTargetPoint({ _pos.x + 1, _pos.y }) < minDistance
			)
		{
			minDistance = calcDistanceToTargetPoint({ _pos.x + 1, _pos.y });
			minDistanceDirection = characters::RIGHT;
		}

		if (
			!isCollusion(characters::LEFT)
			&& (_pos.x - 1 != _lastPosition.x)
			&& calcDistanceToTargetPoint({ _pos.x - 1, _pos.y }) < minDistance
			)
		{
			minDistance = calcDistanceToTargetPoint({ _pos.x - 1, _pos.y });
			minDistanceDirection = characters::LEFT;
		}

		_dir = minDistanceDirection;
		_lastPosition = _pos;
	}
}

void Ghost::setStdMode()
{
	_mode = _stdMode;
}

void Ghost::setMode(std::shared_ptr<Mode> m)
{
	_mode = m;
}

bool Ghost::isInitialized()
{
	return _isInitialized;
}

void Ghost::resetAll()
{
	resetAppearance();
	resetPosition();

	_isInitialized = false;
}

void Ghost::init()
{
	_isInitialized = true;
}

Ghost::Ghost(char** blocks) :
	Characters(blocks), _targetPoint{ -1, -1 }, _lastPosition{-1, -1}, _stdMode(nullptr), _mode(nullptr), _lastCall(0.0f), _isInitialized(false)
{
}
