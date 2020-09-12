/*
 * ScreenDisplay.cpp
 *
 *
 * Author: Nati & Eli
 */

#include "ScreenDisplay.h"

namespace npl {

ScreenDisplay::ScreenDisplay() {

}

ScreenDisplay::~ScreenDisplay() {

}



int ScreenDisplay::getOrder(string somestr)
{
	if(somestr.compare("lu") == 0)
	{
		return 1;
	}
	if(somestr.compare("lcu") == 0)
	{
		return 2;
	}
	if(somestr.compare("ls")  == 0)
	{
		return 3;
	}
	if(somestr.compare("lr")  == 0)
	{
		return 4;
	}
	if(somestr.compare("lru")  == 0)
	{
		return 5;
	}
	if(somestr.compare("x")  == 0)
	{
		return 6;
	}

	return 0;
}

void ScreenDisplay::printMenu()
{
	cout << BOLD(FYEL("                                  *************")) << endl;
	cout << BOLD(FYEL("                                  * MAIN MENU *")) << endl;
	cout << BOLD(FYEL("                                  *************")) << endl << endl;
	cout << BOLD(FWHT("(1) "))<<BOLD(FYEL("lu                         -  List all users")) << endl;
	cout << BOLD(FWHT("(2) "))<<BOLD(FYEL("lcu                        -  List all connected users")) << endl;
	cout << BOLD(FWHT("(3) "))<<BOLD(FYEL("ls                         -  List all sessions (two clients communicating)")) << endl;
	cout << BOLD(FWHT("(4) "))<<BOLD(FYEL("lr                         -  List all rooms")) << endl;
	cout << BOLD(FWHT("(5) "))<<BOLD(FYEL("lru <room name>            -  List all users in this room")) << endl;
	cout << BOLD(FWHT("(6) "))<<BOLD(FYEL("x                          -  Shutdown")) << endl;
}

} /* namespace npl */
