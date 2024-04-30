#ifndef PADDLE_H
#define	PADDLE_H

#include "position.h"
#include <cstddef>

class Paddle
{
public:
	Paddle(Position<std::size_t> startPos)
		: m_centre {startPos}
	{
	}

	const Position<std::size_t>& getPositon() const { return m_centre; }

private:
	Position<std::size_t> m_centre {};

};

#endif