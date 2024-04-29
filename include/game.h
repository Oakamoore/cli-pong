#ifndef GAME_H
#define GAME_H

#include "level.h"
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
	
};

#endif