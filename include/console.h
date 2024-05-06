#ifndef	CONSOLE_H
#define CONSOLE_H

#define NOMINMAX			// Prevents the redefinition of 'std::min' and 'std::max'
#define WIN32_LEAN_AND_MEAN	// Prevents the inclusion of unnecessary sub-headers

#include <windows.h>

namespace Console
{
	// Represents standard output
	const HANDLE hOut {GetStdHandle(STD_OUTPUT_HANDLE)};

	// Default cursor position
	const COORD topLeft {0, 0};

	// Console dimensions
	const int cWidth {1000};
	const int cHeight {500};

	void setSize();
	void updateFrame();
	void clearScreen();
}

#endif