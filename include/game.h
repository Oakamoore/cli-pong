#ifndef GAME_H
#define GAME_H

#include "level.h"
#include "paddle.h"
#include "ball.h"
#include "config.h"
#include <array>
#include <utility>

class Game
{
public:
	void draw();
	void input();
	void update();
	void logic();
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

private:
	Level m_level {};
	Paddle m_playerOne {Config::leftPos};
	Paddle m_playerTwo {Config::rightPos};
	Ball m_ball {Config::midPos};

};

#endif