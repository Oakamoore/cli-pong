#include "level.h"
#include <cassert>

char& Level::operator()(const std::size_t row, const std::size_t column)
{
	assert(row >= 0 && row < s_rows);
	assert(column >= 0 && column < s_columns);

	return m_grid[row][column];
}

