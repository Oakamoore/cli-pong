#include "game.h"
#include <iostream>
#include <chrono>
#include <thread>

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

void Game::run()
{
	using namespace std::chrono_literals;

	auto frameDuration {1s};

	while (true)
	{
		draw();

		std::this_thread::sleep_for(frameDuration);
	}
}