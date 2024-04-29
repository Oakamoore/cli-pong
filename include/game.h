#ifndef GAME_H
#define GAME_H

#include "level.h"
#include "paddle.h"
#include <array>

class Game
{
public:
	void draw();
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

	static constexpr std::array<char, max_symbols> m_symbols {-2, '\xDB', '\xB2', '\xDD'};

private:
	Level m_level {};
	Paddle m_playerOne {{Level::s_centreRow, 1}};
	Paddle m_playerTwo {{Level::s_centreRow, Level::s_columns - 2}};

};

#endif