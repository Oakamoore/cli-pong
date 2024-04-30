#ifndef PADDLE_H
#define	PADDLE_H

#include "position.h"
#include "directions.h"
#include <cstddef>
#include <utility>
	
class Paddle
{
public:
	using Controls = std::pair<char, char>;

	Paddle(Position<std::size_t> startPos)
		: m_centre {startPos}
	{
	}

	const Position<std::size_t>& getPositon() const { return m_centre; }

private:
	Position<std::size_t> m_centre {};
	Directions::Type m_direction {Directions::none}; 
};

#endif