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
	m_currentPos = m_currentPos + Directions::directions[m_direction];

	// Determine the side of the level the ball is on
	m_side = (m_currentPos.col > Level::s_centreColumn ? Level::right : Level::left);

	// The front of the ball is one position in front of the current position
	m_front = m_currentPos + Directions::directions[m_direction];
}

void Ball::horizontalReflect()
{
	using namespace Directions;

	switch (m_direction)
	{
		case north: 
			m_direction = south;
			break;
		case south:
			m_direction = north;
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
		case east:
			m_direction = west;
			break;
		case west:
			m_direction = east;
			break;
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

void Ball::gainPaddleDirection(Directions::Type paddleDirection)
{
	using namespace Directions;

	switch (paddleDirection)
	{
		case north:
			m_side == Level::left ? m_direction = north_east : m_direction = north_west;
			break;
		case south:
			m_side == Level::left ? m_direction = south_east : m_direction = south_west;
			break;
		case none:
			verticalReflect(); // Treat the paddle as a stationary object
			break;
	}
}

