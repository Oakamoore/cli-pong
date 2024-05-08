#ifndef CONFIG_H
#define CONFIG_H

#include "position.h"
#include "level.h"
#include <cstddef>

namespace Config
{
	inline constexpr int maxScore {5};

	// Starting positions of the paddles
	inline constexpr Position<std::size_t> leftPos {Level::s_centreRow, 3};
	inline constexpr Position<std::size_t> rightPos {Level::s_centreRow, Level::s_columns - 4};

	// Starting position of the ball
	inline constexpr Position<std::size_t> midPos {Level::s_centreRow, Level::s_centreColumn};

	// The control scheme for the different paddles
	inline constexpr std::pair<char, char> pOneControls {'W', 'S'};
	inline constexpr std::pair<char, char> pTwoControls {'I', 'K'};
}

#endif