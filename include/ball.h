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
	void horizontalReflect();
	void verticalReflect();

	const Position<std::size_t>& getPosition() const { return m_currentPos; }
	const Position<std::size_t>& getFront() const { return m_front; }
	const Directions::Type& getDirection() const { return m_direction; }

private:
	Position<std::size_t> m_startPos {};
	Position<std::size_t> m_currentPos {};
	Position<std::size_t> m_front {};
	Directions::Type m_direction {};

};

#endif