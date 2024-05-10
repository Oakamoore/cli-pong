#ifndef PADDLE_H
#define	PADDLE_H

#include "position.h"
#include "directions.h"
#include <cstddef>
#include <utility>
	
class Paddle
{
public:
	Paddle(Position<std::size_t> startPos);

	void updatePosition();
	bool isInBounds() const;

	const auto& getPositon() const { return m_centre; }
	const auto getDirection() const { return m_direction; }
	void setDirection(Directions::Type direction) { m_direction = direction; }

private:
	Position<std::size_t> m_centre {};
	Directions::Type m_direction {}; 
};

#endif