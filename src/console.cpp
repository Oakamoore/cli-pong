#include "console.h"
#include <iostream>

namespace Console
{
	void setSize()
	{
		HWND console {GetConsoleWindow()};

		RECT r {};

		// Stores the console's current dimensions
		GetWindowRect(console, &r);

		// Changes the console's size
		MoveWindow(console, r.left, r.top, cWidth, cHeight, TRUE);

		// Prevents the console from being resized
		SetWindowLongPtr(console, GWL_STYLE, GetWindowLongPtr(console, GWL_STYLE) & ~WS_MAXIMIZEBOX & ~WS_SIZEBOX);
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

	void printTabs(int numTabs)
	{
		while (numTabs--)
			std::cout << '\t';
	}

	void printLines(int numLines)
	{
		while (numLines--)
			std::cout << '\n';
	}
}