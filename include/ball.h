#ifndef BALL_H
#define BALL_H

#include "position.h"
#include "directions.h"
#include "level.h"
#include <cstddef>

class Ball
{
public:
	Ball(Position<std::size_t> startPos);

	void updatePosition();
	void horizontalReflect();
	void verticalReflect();
	void gainPaddleDirection(Directions::Type paddleDirection);

	void reset() { *this = {m_startPos}; }

	const Position<std::size_t>& getPosition() const { return m_currentPos; }
	const Position<std::size_t>& getHorizontalFront() const { return m_horizontalFront; }
	const Position<std::size_t>& getVerticalFront() const { return m_verticalFront; }
	const Directions::Type& getDirection() const { return m_direction; }
	const Level::Side& getSide() const { return m_side; }

private:
	Position<std::size_t> m_startPos {};
	Position<std::size_t> m_currentPos {};
	Position<std::size_t> m_horizontalFront {};
	Position<std::size_t> m_verticalFront {};
	Directions::Type m_direction {};
	Level::Side m_side {};

};

#endif