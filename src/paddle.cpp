#include "paddle.h"
#include "level.h"

Paddle::Paddle(Position<std::size_t> startPos)
	: m_centre {startPos}
	, m_direction {Directions::none}
{
}

void Paddle::updatePosition()
{
	if (isInBounds())
	{
		// Modify the centre position of the paddle based on it's direction
		m_centre = m_centre + Directions::positionOffset[m_direction];
	}
}

bool Paddle::isInBounds() const
{
	// Accounts for the added length of the paddle
	static constexpr int topOffset {2};
	static constexpr int bottomOffset {4};

	if (m_centre.row - topOffset <= 0 && m_direction == Directions::north)
		return false;

	if (m_centre.row + bottomOffset > Level::s_rows && m_direction == Directions::south)
		return false;

	return true;
}