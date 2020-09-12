/*
 * ClientInfo.h
 *
 *
 * Author: Nati & Eli
 */

#ifndef CLIENTINFO_H_
#define CLIENTINFO_H_

#include "ClientInterface.h"
#include "Colors.h"

using namespace std;
namespace npl {

class ClientInfo: public ClientInterface {

public:
	virtual bool isInChat();                      // Boolean method that check if a room is active or a session is active
	virtual bool isConnectedToServer() const;     // Boolean method that check if a socket entered the server

	virtual void chatRoomRemoveUser();            // Method that responsible to remove a client from the chat room
	virtual	void printConnectedUsers();           // The method responsible to print connected users to the screen
	virtual	void printStatus();                   // The method responsible to print the status of the client
	virtual	void printUsersList();                // The method responsible to printing the users list
	virtual	void printActiveRooms();              // The method responsible to print the active rooms
	virtual void clearOtherSideVector();          // Clearing the otherSide's vector

	void getConnectedUsersList();                 // Calling to the actual printing method of active users list
	void getUsersList();                          // Calling to the actual printing method of users list
	void getRoomList();                           // Calling to the actual printing method of chat room list
	void getUsersInSpecificRoom(string roomName); // Calling to the actual printing method of users in a specific room

};

} /* namespace npl */

#endif /* CLIENTINFO_H_ */
