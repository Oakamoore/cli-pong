#include "ball.h"
#include "random.h"

Ball::Ball(Position<std::size_t> startPos)
	: m_startPos {startPos}
	, m_currentPos {m_startPos}
{
	// The ball object is given a random horizontal direction upon construction
	m_direction = static_cast<Directions::Type>(Random::chooseBetween<int>(Directions::east, Directions::west));
}

void Ball::updatePosition()
{
	// Modify the current position of the ball based on its direction
	m_currentPos.row += Directions::directions[m_direction].row;
	m_currentPos.col += Directions::directions[m_direction].col;
}