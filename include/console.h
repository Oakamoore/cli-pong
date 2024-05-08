#ifndef	CONSOLE_H
#define CONSOLE_H

// Prevents the redefinition of 'std::min' and 'std::max'
#define NOMINMAX		

// Prevents the inclusion of unnecessary sub-headers
#define WIN32_LEAN_AND_MEAN	

#include <windows.h>

namespace Console
{
	// Represents standard output
	const HANDLE hOut {GetStdHandle(STD_OUTPUT_HANDLE)};

	// Default cursor position
	const COORD topLeft {0, 0};

	// Console dimensions
	const int cnslWidth {1000};
	const int cnslHeight {600};

	void setSize();
	void updateFrame();
	void clearScreen();
	void printTabs(int numTabs);
	void printLines(int numLines);
}

#endif