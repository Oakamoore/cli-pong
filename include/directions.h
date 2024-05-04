#ifndef DIRECTIONS_H
#define DIRECTIONS_H

#include "position.h"
#include <array>
#include <unordered_map>
#include <utility>
#include <string_view>

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

	// Opposite horizontal directional pairs
	inline const std::unordered_map<Type, Type> horizontalOpposite
	{
		{north, south},
		{south, north},
		{north_east, south_east},
		{south_east, north_east},
		{south_west, north_west},
		{north_west, south_west}
	};

	// Opposite vertical directional pairs
	inline const std::unordered_map<Type, Type> verticalOpposite
	{
		{east, west},
		{west, east},
		{north_east, north_west},
		{south_east, south_west},
		{south_west, south_east},
		{north_west, north_east}
	};

	// Maps an intercardinal direction to its base cardinal directions
	inline const std::unordered_map<Type, std::pair<Type, Type>> intercardinalSplit
	{
		{south_east, {south, east}},
		{north_east, {north, east}},
		{south_west, {south, west}},
		{north_west, {north, west}}
	};

	inline Type& operator++(Type& direction)
	{
		// Wraps the enumerator around 
		if (direction == max_directions)
			direction = none;
		else
			direction = static_cast<Type>(direction + 1);

		return direction;
	}

	inline constexpr std::array<std::string_view, max_directions> text
	{{
		{"none "},
		{"north"},
		{"east"},
		{"south"},
		{"west"},
		{"north east"},
		{"south east"},
		{"south west"},
		{"north west"}
	}};

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
