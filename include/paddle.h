#ifndef PADDLE_H
#define	PADDLE_H

#include "position.h"
#include "directions.h"
#include <cstddef>
#include <utility>
	
class Paddle
{
public:
	Paddle(Position<std::size_t> startPos)
		: m_centre {startPos}
	{
	}

	void updatePosition();
	bool isInBounds() const;

	const Position<std::size_t>& getPositon() const { return m_centre; }
	const Directions::Type getDirection() const { return m_direction; }
	void setDirection(Directions::Type direction) { m_direction = direction; }

private:
	Position<std::size_t> m_centre {};
	Directions::Type m_direction {Directions::none}; 
};

#endif