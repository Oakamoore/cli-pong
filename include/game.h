#ifndef GAME_H
#define GAME_H

#include "level.h"
#include "paddle.h"
#include "position.h"
#include <array>

class Game
{
public:
	void draw();
	void input();
	void run();

private:
	enum Symbols
	{
		ball,
		paddle,
		level_border,
		level_centre,
		max_symbols
	};

	static constexpr std::array<char, max_symbols> s_symbols {-2, '\xDB', '\xB2', '\xDD'};

	// Starting positions of the paddles
	static constexpr Position<std::size_t> s_left {Level::s_centreRow, 1};
	static constexpr Position<std::size_t> s_right {Level::s_centreRow, Level::s_columns - 2};

	// The control scheme for the different paddles
	static constexpr Paddle::Controls s_pOneControls {'W', 'S'};
	static constexpr Paddle::Controls s_pTwoControls {'I', 'K'};

private:
	Level m_level {};
	Paddle m_playerOne {s_left, s_pOneControls};
	Paddle m_playerTwo {s_right, s_pTwoControls};

};

#endif