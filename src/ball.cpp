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
	m_currentPos = m_currentPos + Directions::positionOffset[m_direction];

	// Determine the side of the level the ball is on
	m_side = (m_currentPos.col > Level::s_centreColumn ? Level::right : Level::left);

	using enum Directions::Type;

	// Sets the position of each 'front' based on the ball's current direction
	for (Directions::Type direction {north}; direction < max_directions; ++direction)
	{
		// Accounts for the cardinal directions
		if ((direction >= north && direction <= west) && m_direction == direction)
		{
			m_verticalFront = m_currentPos + Directions::positionOffset[direction];
			m_horizontalFront = m_verticalFront;
		}

		// Accounts for the intercardinal directions 
		if ((direction >= north_east && direction <= north_west) && m_direction == direction)
		{
			auto [vertical, horizontal] { Directions::intercardinalSplit.at(direction) };

			m_verticalFront = m_currentPos + Directions::positionOffset[vertical];
			m_horizontalFront = m_currentPos + Directions::positionOffset[horizontal];
		}
	}
}

void Ball::horizontalReflect()
{
	// Sets the balls direction to its horizontal opposite
	m_direction = Directions::horizontalOpposite.at(m_direction);
}

void Ball::verticalReflect()
{
	// Sets the balls direction to its vertical opposite
	m_direction = Directions::verticalOpposite.at(m_direction);
}

void Ball::gainPaddleDirection(Directions::Type paddleDirection)
{
	using enum Directions::Type;

	// The ball adopts the paddle's vertical directional component
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

void Ball::reset()
{
	m_currentPos = m_startPos;

	// The player scored against receives the ball
	switch (m_side)
	{
		case Level::left: 
			m_direction = Directions::west;
			break;
		case Level::right:
			m_direction = Directions::east;
			break;
	}
}