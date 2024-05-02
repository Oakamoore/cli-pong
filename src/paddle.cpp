#include "paddle.h"
#include "level.h"

void Paddle::updatePosition()
{
	// Modify the centre position of the paddle based on it's direction
	m_centre.row += Directions::directions[m_direction].row;
	m_centre.col += Directions::directions[m_direction].col;
}

bool Paddle::isInBounds() const
{
	// Accounts for the adding length of the paddle
	static const int topOffset {2};
	static const int bottomOffset {4};

	if (m_centre.row - topOffset <= 0 && m_direction == Directions::north)
		return false;

	if (m_centre.row + bottomOffset > Level::s_rows && m_direction == Directions::south)
		return false;

	return true;
}