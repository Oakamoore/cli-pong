#ifndef BALL_H
#define BALL_H

#include "position.h"
#include "directions.h"
#include <cstddef>

class Ball
{
public:
	Ball(Position<std::size_t> startPos)
		: m_startPos {startPos}
		, m_currentPos {m_startPos}
	{
	}

	const Position<std::size_t>& getPosition() const { return m_currentPos; };;

private:
	Position<std::size_t> m_startPos {};
	Position<std::size_t> m_currentPos {};
	Directions::Type m_direction {Directions::none};

};

#endif