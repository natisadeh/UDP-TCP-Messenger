/*
 * ScreenDisplay.cpp
 *
 *
 * Author: Nati & Eli
 */

#include "ScreenDisplay.h"

namespace npl {

void ScreenDisplay::PrintMenu()
{
	cout << BOLD(FYEL("                                  *************")) << endl;
	cout << BOLD(FYEL("                                  * MAIN MENU *")) << endl;
	cout << BOLD(FYEL("                                  *************")) << endl << endl;
	cout << BOLD(FWHT("(1)  "))<<BOLD(FYEL("c <IP>                         -  Connect to the server in the given ip ")) << endl;
	cout << BOLD(FWHT("(2)  "))<<BOLD(FYEL("register <user> <password>     -  Register a new user                   ")) << endl;
	cout << BOLD(FWHT("(3)  "))<<BOLD(FYEL("login <user> <password>        -  Login with the user and password      ")) << endl;
	cout << BOLD(FWHT("(4)  "))<<BOLD(FYEL("o <username>                   -  Open a session with a user            ")) << endl;
	cout << BOLD(FWHT("(5)  "))<<BOLD(FYEL("lu                             -  Print the users list from the server  ")) << endl;
	cout << BOLD(FWHT("(6)  "))<<BOLD(FYEL("lcu                            -  Print the connected users list        ")) << endl;
	cout << BOLD(FWHT("(7)  "))<<BOLD(FYEL("or <room name>                 -  Create a chat room                    ")) << endl;
	cout << BOLD(FWHT("(8)  "))<<BOLD(FYEL("er <room name>                 -  Enter a chat room                     ")) << endl;
	cout << BOLD(FWHT("(9)  "))<<BOLD(FYEL("cr <room name>                 -  Close a room                          ")) << endl;
	cout << BOLD(FWHT("(10) "))<<BOLD(FYEL("lr                             -  Print all rooms                       ")) << endl;
	cout << BOLD(FWHT("(11) "))<<BOLD(FYEL("lru <room name>                -  Print all users in this room          ")) << endl;
	cout << BOLD(FWHT("(12) "))<<BOLD(FYEL("s <message>                    -  Send a message                        ")) << endl;
	cout << BOLD(FWHT("(13) "))<<BOLD(FYEL("cs                             -  Disconnect the open session           ")) << endl;
	cout << BOLD(FWHT("(14) "))<<BOLD(FYEL("l                              -  Print the current status of the client")) << endl;
	cout << BOLD(FWHT("(15) "))<<BOLD(FYEL("p                              -  Print the instructions                ")) << endl;
	cout << BOLD(FWHT("(16) "))<<BOLD(FYEL("d                              -  Disconnect from the server            ")) << endl;
	cout << BOLD(FWHT("(17) "))<<BOLD(FYEL("x                              -  Close the app                         ")) << endl;

}


int ScreenDisplay::getOrder(string somestr)
{
   //string lu = "lu";
	if(somestr.compare("c") == 0)
	{
		return 1;
	}
	if(somestr.compare("register") == 0)
	{
		return 2;
	}
	if(somestr.compare("login")  == 0)
	{
		return 3;
	}
	if(somestr.compare("o")  == 0)
	{
		return 4;
	}
	if(somestr.compare("lu")  == 0)
	{
		return 5;
	}
	if(somestr.compare("lcu")  == 0)
	{
		return 6;
	}
	if(somestr.compare("or")  == 0)
	{
		return 7;
	}
	if(somestr.compare("er")  == 0)
	{
		return 8;
	}
	if(somestr.compare("cr")  == 0)
	{
		return 9;
	}
	if(somestr.compare("lr")  == 0)
	{
		return 10;
	}
	if(somestr.compare("lru")  == 0)
	{
		return 11;
	}
	if(somestr.compare("s")  == 0)
	{
		return 12;
	}
	if(somestr.compare("cs")  == 0)
	{
		return 13;
	}
	if(somestr.compare("l")  == 0)
	{
		return 14;
	}
	if(somestr.compare("p")  == 0)
	{
		return 15;
	}
	if(somestr.compare("d")  == 0)
	{
		return 16;
	}
	if(somestr.compare("x")  == 0)
	{
		return 17;
	}

	return 0;


}
} /* namespace npl */

