#include "console.h"
#include <iostream>

namespace Console
{
	void setSize()
	{

	}

	void updateFrame()
	{
		std::cout.flush();

		SetConsoleCursorPosition(hOut, topLeft);
	}

	void clearScreen()
	{
		CONSOLE_SCREEN_BUFFER_INFO csbi {};

		std::cout.flush();

		// Current width and height of the console 
		// Return early if there's an error
		if (!GetConsoleScreenBufferInfo(hOut, &csbi))
			return;

		// Total number of cells in the console
		DWORD cellCount {static_cast<DWORD>(csbi.dwSize.X * csbi.dwSize.Y)};

		// Number of characters filled
		DWORD filledCount {};

		// Flood fill the console with spaces
		FillConsoleOutputCharacter(hOut, TEXT(' '), cellCount, topLeft, &filledCount);

		// Reset the attributes of every character
		FillConsoleOutputAttribute(hOut, csbi.wAttributes, cellCount, topLeft, &filledCount);

		SetConsoleCursorPosition(hOut, topLeft);
	}
}