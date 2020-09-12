/*
 * MCA.cpp
 *
 *
 * Author: Nati & Eli
 */

#include <iostream>
#include "ClientManager.h"
#include "ScreenDisplay.h"
#include "Colors.h"

using namespace std;

int main() {

	ClientManager clientManager;
	ScreenDisplay sd;

	bool running = true;

	sd.PrintMenu();

	while(running)
	{
		string command;
		string temp1;
		string temp2;
		cin >> command;

		switch(sd.getOrder(command))
		{
		case 1:
			cin >> temp1;
			if(clientManager.connectToServer(temp1,MSNGR_PORT))
				cout << BOLD(FGRN("The connection to the server was successfully "))<< endl;
			else
				cout << BOLD(FRED("Failed to connect"))<<endl;
		    break;

		case 2:
			cin >> temp1;
			cin >> temp2;
			clientManager.userRegister(temp1,temp2,REGISTRATION_REQUEST);
			break;

		case 3:
			cin >> temp1;
			cin >> temp2;
			clientManager.userLogin(temp1,temp2,LOGIN_REQUEST);
			break;

		case 4:
			cin >> temp1;
			clientManager.peersSession(temp1);
			break;

		case 5:
			clientManager.getUsersList();
			break;

		case 6:
			clientManager.getConnectedUsersList();
			break;

		case 7:
			cin >> temp1;
			clientManager.chatRoomCreate(temp1);
			break;
		case 8:
			cin >> temp1;
			clientManager.chatRoomEnter(temp1);
			break;

		case 9:
			cin >> temp1;
			clientManager.chatRoomDelete(temp1);
			break;

		case 10:
			clientManager.getRoomList();
			break;

		case 11:
			cin >> temp1;
			clientManager.getUsersInSpecificRoom(temp1);
			break;

		case 12:
			getline(std::cin,temp1);
			if(!clientManager.sendMsg(temp1))
			cout << BOLD(FRED("There is not active session or you're not in a room")) << endl;
			break;

		case 13:
			if(!clientManager.leaveRoomOrCloseSession())
			cout << BOLD(FRED("There is not active session or a room to close session")) << endl;
			break;

		case 14:
			clientManager.printStatus();
			break;
		case 15:
			sd.PrintMenu();
			break;
		case 16:
			if (clientManager.isConnectedToServer())
			{
				clientManager.disconnect();
				cout << BOLD(FMAG("You have been disconnected from the server")) << endl;
			}
			break;

		case 17:
			if (clientManager.isConnectedToServer())
			{
				clientManager.disconnect();
			}
			cout << BOLD(FMAG("Good bye :)")) << endl;
			running=false;
			break;

		default:

		   cout <<"Wrong input, please try again"<<endl;
		   break;

		}
	}
}
