/*
 * MSA.cpp
 *
 *
 * Author: Nati & Eli
 */

#include <iostream>
#include "ServerManager.h"
#include "LoginAndRegister.h"
#include "ServerInfo.h"
#include "ScreenDisplay.h"
using namespace std;

int main() {

	ServerManager serverManager;
	Login registration(&serverManager);
	Connection connection(&registration);
	ScreenDisplay sd;


	bool running=true;
    sd.printMenu();


			while (running==true)
				{
				string command, chatRoom;
				cin >> command;

                switch (sd.getOrder(command))
                {
                case 1:
                	serverManager.printUsers();
                	break;

                case 2:
                	serverManager.printActiveUsers();
                    break;

                case 3:
                	serverManager.printSessions();
                    break;

                case 4:
                	serverManager.printRooms();
                    break;

                case 5:
            		cin>>chatRoom;
            		serverManager.printUsersInSpecificRoom(chatRoom);
            		break;

                case 6:
					cout<<"Server terminated, Good bye :)"<<endl;
					running = false;
					break;

                default:
                	cout <<"Wrong input, please try again"<<endl;
                	break;
                }
		}
}


