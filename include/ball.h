#ifndef BALL_H
#define BALL_H

#include "position.h"
#include "directions.h"
#include <cstddef>

class Ball
{
public:
	Ball(Position<std::size_t> startPos);

	void updatePosition();
	void reflect();

	const Position<std::size_t>& getPosition() const { return m_currentPos; }
	const Position<std::size_t>& getFront() const { return m_front; }
	const Directions::Type& getDirection() const { return m_direction; }
	void setDirection(Directions::Type direction) { m_direction = direction; }

private:
	Position<std::size_t> m_startPos {};
	Position<std::size_t> m_currentPos {};
	Position<std::size_t> m_front {};
	Directions::Type m_direction {};

};

#endif