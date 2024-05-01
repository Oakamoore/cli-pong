#include "ball.h"
#include "random.h"

Ball::Ball(Position<std::size_t> startPos)
	: m_startPos {startPos}
	, m_currentPos {m_startPos}
{
	// The ball object is given a random horizontal direction upon construction
	//m_direction = static_cast<Directions::Type>(Random::chooseBetween<int>(Directions::east, Directions::west));

	m_direction = Directions::north_east;
}

void Ball::updatePosition()
{
	// Modify the current position of the ball based on its direction
	m_currentPos.row += Directions::directions[m_direction].row;
	m_currentPos.col += Directions::directions[m_direction].col;

	// The front of the ball is one position in front of the current position
	m_front = m_currentPos;

	m_front.row += Directions::directions[m_direction].row;
	m_front.col += Directions::directions[m_direction].col;
}

void Ball::horizontalReflect()
{
	using namespace Directions;

	switch (m_direction)
	{
		case north: 
			m_direction = south;
			break;
		case east:
			m_direction = west;
			break;
		case south:
			m_direction = north;
			break;
		case west:
			m_direction = east;
			break;
		case north_east:
			m_direction = south_east;
			break;
		case south_east:
			m_direction = north_east;
			break;
		case south_west:
			m_direction = north_west;
			break;
		case north_west:
			m_direction = south_west;
			break;
	}
}

void Ball::verticalReflect()
{
	using namespace Directions;

	switch (m_direction)
	{
		case north_east:
			m_direction = north_west;
			break;
		case south_east:
			m_direction = south_west;
			break;
		case south_west:
			m_direction = south_east;
			break;
		case north_west:
			m_direction = north_east;
			break;
	}
}

