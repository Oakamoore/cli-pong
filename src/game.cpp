#include "game.h"
#include <iostream>
#include <chrono>
#include <thread>

void Game::draw()
{
	system("cls");

	std::cout << "\n\n\n";

	for (std::size_t row {0}; row < Level::s_rows; ++row)
	{
		std::cout << "\t\t\t       ";

		for (std::size_t col {0}; col < Level::s_columns; ++col)
		{
			if (row == 0 || row == Level::s_rows - 1)
				m_level.setGrid()[row][col] = m_symbols[level_border];

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