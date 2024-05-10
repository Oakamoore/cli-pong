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
	void reset();

	const auto& getPosition() const { return m_currentPos; }
	const auto& getHorizontalFront() const { return m_horizontalFront; }
	const auto& getVerticalFront() const { return m_verticalFront; }
	const auto& getSide() const { return m_side; }

private:
	Position<std::size_t> m_startPos {};
	Position<std::size_t> m_currentPos {};
	Position<std::size_t> m_horizontalFront {};
	Position<std::size_t> m_verticalFront {};
	Directions::Type m_direction {};
	Level::Side m_side {};

};

#endif