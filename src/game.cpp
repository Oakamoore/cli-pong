#define NOMINMAX            // Prevents the redefinition of 'std::min' and 'std::max'
#define WIN32_LEAN_AND_MEAN // Prevents the inclusion of unnecessary sub-headers

#include "game.h"
#include "directions.h"
#include <iostream>
#include <chrono>
#include <thread>
#include <windows.h>

static void clearScreen()
{
	// Represents standard output
	static const HANDLE hOut {GetStdHandle(STD_OUTPUT_HANDLE)};

	// Sends all written characters directly to the console
	std::cout.flush();

	// Default cursor position
	COORD topLeft {0, 0};

	SetConsoleCursorPosition(hOut, topLeft);
}

void Game::draw()
{
	auto drawPaddle
	{
		[&](const Paddle& p)
		{
			const auto& [row, col] { p.getPositon() };

			// Lengthens the paddle based on its centre position
			m_level.setGrid()[row][col] = s_symbols[paddle];
			m_level.setGrid()[row - 1][col] = s_symbols[paddle];
			m_level.setGrid()[row + 1][col] = s_symbols[paddle];
		}
	};

	auto drawBall
	{
		[&](const Ball& b)
		{
			const auto& [row, col] { b.getPosition() };

			m_level.setGrid()[row][col] = s_symbols[ball];
		}
	};

	// Wipes the terminal
	clearScreen();

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

			drawPaddle(m_playerOne);
			drawPaddle(m_playerTwo);

			drawBall(m_ball);

			std::cout << m_level.getGrid()[row][col];
		}

		std::cout << '\n';
	}
}

void Game::input()
{
	const auto& [pOneUp, pOneDown] { s_pOneControls };
	const auto& [pTwoUp, pTwoDown] { s_pTwoControls };

	// Raw terminal input, to register combinded keystrokes
	// When there is no registered input, reset to 'none'

	// Player one key press response 
	if (GetKeyState(pOneUp) < 0)
	{
		m_playerOne.setDirection(Directions::north);
	}
	else if (GetKeyState(pOneDown) < 0)
	{
		m_playerOne.setDirection(Directions::south);
	}
	else
	{
		m_playerOne.setDirection(Directions::none);
	}

	// Player two key press reponse
	if (GetKeyState(pTwoUp) < 0)
	{
		m_playerTwo.setDirection(Directions::north);
	}
	else if (GetKeyState(pTwoDown) < 0)
	{
		m_playerTwo.setDirection(Directions::south);
	}
	else
	{
		m_playerTwo.setDirection(Directions::none);
	}

	std::cout << "\n\nPlayer 1 Direction: " << Directions::text[m_playerOne.getDirection()] << '\n';
	std::cout << "Player 2 Direction: " << Directions::text[m_playerTwo.getDirection()] << '\n';
	std::cout << "Ball Direction: " << Directions::text[m_ball.getDirection()] << '\n';
}

void Game::update()
{
	auto isInBounds
	{
		[](const Paddle& p)
		{
			auto row { p.getPositon().row };

			// Takes into account the added length of the paddle
			// and it's current direction
			
			if (row + 4 > Level::s_rows && p.getDirection() == Directions::south)
				return false;

			if (row - 2 <= 0 && p.getDirection() == Directions::north)
				return false;

			return true;
		}
	};

	if (isInBounds(m_playerOne))
		m_playerOne.updatePosition();

	if (isInBounds(m_playerTwo))
		m_playerTwo.updatePosition();

	m_ball.updatePosition();
}

void Game::logic()
{
	const auto& [row, col] { m_ball.getFront() };

	// The object directly in front of the ball
	char collisionObject {m_level.getGrid()[row][col]};

	switch (collisionObject)
	{
		case s_symbols[level_border]: 
			m_ball.horizontalReflect();
			break;
		case s_symbols[paddle]:
			m_ball.verticalReflect();
			break;
	}
}

void Game::run()
{
	using namespace std::chrono_literals;

	auto frameDuration {0.1s};

	while (true)
	{
		draw();
		input();
		update();
		logic();

		std::this_thread::sleep_for(frameDuration);
	}
}