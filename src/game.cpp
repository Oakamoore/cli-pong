#define NOMINMAX            // Prevents the redefinition of 'std::min' and 'std::max'
#define WIN32_LEAN_AND_MEAN // Prevents the inclusion of sub-headers

#include "game.h"
#include <iostream>
#include <chrono>
#include <thread>
#include <windows.h>

void Game::draw()
{
	auto drawPaddle
	{
		[&](const Paddle& p)
		{
			auto [row, col] { p.getPositon() };

			// Lengthens the paddle based on its centre position
			m_level.setGrid()[row][col] = s_symbols[paddle];
			m_level.setGrid()[row - 1][col] = s_symbols[paddle];
			m_level.setGrid()[row + 1][col] = s_symbols[paddle];
		}
	};

	system("cls");

	std::cout << "\n\n\n";

	for (std::size_t row {0}; row < Level::s_rows; ++row)
	{
		std::cout << "\t\t\t       ";

		for (std::size_t col {0}; col < Level::s_columns; ++col)
		{
			// Adds padding
			m_level.setGrid()[row][col] = ' ';

			// Draws the level's top and bottom borders
			if (row == 0 || row == Level::s_rows - 1)
				m_level.setGrid()[row][col] = s_symbols[level_border];

			// Draws the level's centre line, excluding the top and bottom rows 
			if (col == Level::s_centreColumn && (row != 0 && row != Level::s_rows - 1))
				m_level.setGrid()[row][col] = s_symbols[level_centre];

			// Draws the paddles at opposite ends of the level
			drawPaddle(m_playerOne);
			drawPaddle(m_playerTwo);

			std::cout << m_level.getGrid()[row][col];
		}

		std::cout << '\n';
	}
}

void Game::input()
{
	const auto [pOneUp, pOneDown] { s_pOneControls };
	const auto [pTwoUp, pTwoDown] { s_pTwoControls };

	// Raw terminal input, to register combinded keystrokes

	if (GetKeyState(pOneUp) < 0)
		std::cout << pOneUp;
	else if (GetKeyState(pOneDown) < 0)
		std::cout << pOneDown;

	if (GetKeyState(pTwoUp) < 0)
		std::cout << pTwoUp;
	else if (GetKeyState(pTwoDown) < 0)
		std::cout << pTwoDown;
}

void Game::run()
{
	using namespace std::chrono_literals;

	auto frameDuration {1s};

	while (true)
	{
		draw();
		input();

		//std::this_thread::sleep_for(frameDuration);
	}
}