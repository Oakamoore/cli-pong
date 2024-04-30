#ifndef DIRECTIONS_H
#define DIRECTIONS_H

#include "position.h"
#include <array>

namespace Directions
{
	enum Type
	{
		none, 
		north, 
		east,
		south,
		west,
		north_east,
		south_east,
		south_west,
		north_west,
		max_directions
	};

	inline constexpr std::array<Position<int>, max_directions> directions
	{{
		{0, 0},    // None
		{-1, 0},   // North
		{0, 1},    // East
		{1, 0},    // South
		{0, -1},   // West
		{-1, 1},   // North East
		{1, 1},    // South East
		{1, -1},   // South West
		{-1, -1},  // North West
	}};
}

#endif
