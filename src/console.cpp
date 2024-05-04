#include "console.h"
#include <iostream>

namespace Console
{
	void updateFrame()
	{
		// Sends all characters written to 
		// 'std::cout' directly to the console
		std::cout.flush();

		SetConsoleCursorPosition(hOut, topLeft);
	}

	void clearScreen()
	{

	}
}