#include "game.h"
#include "directions.h"
#include "console.h"
#include <iostream>
#include <chrono>
#include <thread>

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

	// Update game elements that have 
	// changed since the last frame
	Console::updateFrame();

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

			// Drawing the position in front of the ball - checking bug
			auto [hr, hc] { m_ball.getHorizontalFront() };
			auto [vr, vc] { m_ball.getVerticalFront() };

			m_level.setGrid()[hr][hc] = '-';
			m_level.setGrid()[vr][vc] = '-';

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
		m_playerOne.setDirection(Directions::north);
	else if (GetKeyState(pOneDown) < 0)
		m_playerOne.setDirection(Directions::south);
	else
		m_playerOne.setDirection(Directions::none);
	
	// Player two key press reponse
	if (GetKeyState(pTwoUp) < 0)
		m_playerTwo.setDirection(Directions::north);
	else if (GetKeyState(pTwoDown) < 0)
		m_playerTwo.setDirection(Directions::south);
	else
		m_playerTwo.setDirection(Directions::none);

	// Either paddle is at a level border
	// and a respective key is still being pressed

	if((GetKeyState(pOneUp) < 0 || GetKeyState(pOneDown) < 0) && !m_playerOne.isInBounds())
		m_playerOne.setDirection(Directions::none);

	if ((GetKeyState(pTwoUp) < 0 || GetKeyState(pTwoDown) < 0) && !m_playerTwo.isInBounds())
		m_playerTwo.setDirection(Directions::none);

	std::cout << "\n\nPlayer 1 Direction: " << Directions::text[m_playerOne.getDirection()] << '\n';
	std::cout << "Player 2 Direction: " << Directions::text[m_playerTwo.getDirection()] << '\n';
	std::cout << "Ball Direction: " << Directions::text[m_ball.getDirection()];
}

void Game::update()
{
	if (m_playerOne.isInBounds())
		m_playerOne.updatePosition();

	if (m_playerTwo.isInBounds())
		m_playerTwo.updatePosition();

	// TEMP
	if (m_ball.getPosition().col == Level::s_columns - 2 || m_ball.getPosition().col == 1)
		m_ball.reset();

	m_ball.updatePosition();
}

void Game::logic()
{
	const auto& [hRow, hCol] { m_ball.getHorizontalFront() };
	const auto& [vRow, vCol] { m_ball.getVerticalFront() };

	// The objects directly in front of the ball in a given axis
	char verticalCollisionObject {m_level.getGrid()[vRow][vCol]};
	char horizontalCollisionObject {m_level.getGrid()[hRow][hCol]};

	if (verticalCollisionObject == s_symbols[level_border])
	{
		m_ball.horizontalReflect();
	}

	if (horizontalCollisionObject == s_symbols[paddle])
	{
		if (m_ball.getSide() == Level::left)
			m_ball.gainPaddleDirection(m_playerOne.getDirection());
		else
			m_ball.gainPaddleDirection(m_playerTwo.getDirection());
	}

	std::cout << ", Side:" << (m_ball.getSide() ? " Right\n" : "  Left\n");
}

void Game::run()
{
	using namespace std::chrono_literals;

	const auto frameDuration {1ms};

	while (true)
	{
		draw();
		input();
		update();
		logic();

		std::this_thread::sleep_for(frameDuration);
	}
}