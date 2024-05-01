#ifndef BALL_H
#define BALL_H

#include "position.h"
#include "directions.h"
#include <cstddef>

class Ball
{
public:
	Ball(Position<std::size_t> startPos);

	const Position<std::size_t>& getPosition() const { return m_currentPos; }
	const Directions::Type& getDirection() const { return m_direction; }

private:
	Position<std::size_t> m_startPos {};
	Position<std::size_t> m_currentPos {};
	Directions::Type m_direction {};

};

#endif