#ifndef MENU_H
#define MENU_H

#include "console.h"

namespace Menu
{
	enum Options
	{
		play,
		exit
	};
	
	// Allows the menu options to be navigated through
	Options operator++(Options& option);
	Options operator--(Options& option);

	void displayTitle();
	Options getOption();
}

#endif