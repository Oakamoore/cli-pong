#include "console.h"
#include "menu.h"
#include "game.h"

int main()
{
	// Set size, and prevent resizing
	Console::setSize();
	
	bool isRunning {true};

	while (isRunning)
	{
		Menu::Options option {Menu::getOption()};

		Game game {};

		switch (option)
		{
			case Menu::play:
				game.run();
				continue;
			case Menu::exit:
				isRunning = false;
				break;
		}
	}

	return 0;
}