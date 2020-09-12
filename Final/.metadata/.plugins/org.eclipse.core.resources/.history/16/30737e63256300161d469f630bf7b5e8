/*
 * ClientInterface.h
 *
 *
 * Author: Nati & Eli
 */

#ifndef CLIENTINTERFACE_H_
#define CLIENTINTERFACE_H_

#include <vector>
#include "MThread.h"
#include "TCPSocket.h"
#include "UDPmessenger.h"
#include "TCPMessengerProtocol.h"
#include "OtherSide.h"

using namespace std;

namespace npl {

class ClientInterface: public MThread {

protected:
	TCPSocket *serverSocket;
	UDPmessenger *UDPmsgr;

	OtherSide otherSide;
	vector<OtherSide*> chatUsers;

	string userName;
	string roomName;

	bool running;
	bool isSessionActive;
	bool isRoomActive;
	bool isLogin;
	bool isConnected;

public:
	virtual bool isInChat()=0;                  // Boolean method that check if a room is active or a session is active
	virtual bool isConnectedToServer() const=0; // Boolean method that check if a socket entered the server

	virtual void chatRoomRemoveUser()=0;        // Method that responsible to remove a client from the chat room
	virtual void clearOtherSideVector()=0;      // Clearing the otherSide's vector

	virtual void printConnectedUsers()=0;       // The method responsible to print connected users to the screen
	virtual void printStatus()=0;               // The method responsible to print the status of the client
	virtual void printUsersList()=0;            // The method responsible to printing the users list
	virtual void printActiveRooms()=0;          // Print list of all chat rooms

	virtual ~ClientInterface(){}                // Virtual destructor
};

} /* namespace npl */

#endif /* CLIENTINTERFACE_H_ */
