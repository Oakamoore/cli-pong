#include "paddle.h"

void Paddle::updatePosition()
{
	// Modify the centre position of the paddle based on it's direction
	m_centre.row += Directions::directions[m_direction].row;
	m_centre.col += Directions::directions[m_direction].col;
}
