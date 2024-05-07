#include "menu.h"
#include <string_view>
#include <iostream>
#include <string>
#include <cstddef>

namespace Menu
{
	void displayTitle()
	{
		Console::clearScreen();

		std::cout << R"(




					      ____     ___    _   _    ____ 
					     |  _ \   / _ \  | \ | |  / ___|
					     | |_) | | | | | |  \| | | |  _ 
				   	     |  __/  | |_| | | |\  | | |_| |
					     |_|      \___/  |_| \_|  \____|






					       (Navigate using arrow keys)
				    		  (Select using enter)


		)";

		Console::printLines(4);
	}

	Options operator++(Options& option)
	{
		// Ensure enumerator is valid
		if (option == exit)
			option = exit;
		else
			option = static_cast<Options>(option + 1);

		return option;
	}

	Options operator--(Options& option)
	{
		// Ensure enumerator is valid
		if (option == play)
			option = play;
		else
			option = static_cast<Options>(option - 1);

		return option;
	}

	Options getOption()
	{
		Options option {};

		bool hasSelected {};
		bool isDisplaying {};

		while (!hasSelected)
		{
			if (option == play && !isDisplaying)
			{
				displayTitle();

				Console::printTabs(7);
				std::cout << "   Play  <--\n";

				Console::printTabs(7);
				std::cout << "   Exit\n";

				isDisplaying = true;
			}
			else if (option == exit && !isDisplaying)
			{
				displayTitle();

				Console::printTabs(7);
				std::cout << "   Play\n";
				
				Console::printTabs(7);
				std::cout << "   Exit  <--\n";

				isDisplaying = true;
			}

			if (isDisplaying)
			{
				if (GetKeyState(VK_UP) < 0 && option != play)
				{
					--option;
					isDisplaying = false;
				}
				
				if (GetKeyState(VK_DOWN) < 0 && option != exit)
				{
					++option;
					isDisplaying = false;
				}
				
				if (GetKeyState(VK_RETURN) < 0) // An option is selected
					hasSelected = true;
			}
		}

		Console::clearScreen();

		return option;
	}
}