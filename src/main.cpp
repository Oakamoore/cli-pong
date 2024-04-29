#include "level.h"
#include <iostream>
#include <chrono>
#include <thread>

int main()
{
	Level level {};

	using namespace std::chrono_literals;

	while (true)
	{
		system("cls");

		std::cout << "\n\t\t\t\t\t\tPlayer 1: 0\t Player 2: 0";
		std::cout << "\n\n\n";

		for (auto& row : level.setGrid())
		{
			std::cout << "\t\t\t       ";

			for (auto& col : row)
			{
				col = '#';
				std::cout << col;
			}

			std::cout << '\n';
		}

		std::this_thread::sleep_for(1s);
	}

	return 0;
}