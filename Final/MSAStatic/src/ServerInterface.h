/*
 * ServerInterface.h
 *
 *
 * Author: Nati & Eli
 */


#ifndef SERVERINTERFACE_H_
#define SERVERINTERFACE_H_

#include <MThread.h>
#include <map>
#include "MThread.h"
#include "TCPSocket.h"
#include "MultipleTCPSocketListener.h"
#include "User.h"
#include "TCPMessengerProtocol.h"
#include "Colors.h"

using namespace std;

class User;

namespace npl {

class ServerInterface: public MThread {


protected:
	map<string,User*>::iterator getBeginIter();
	map<string,User*>::iterator getEndIter();

	const char* usersFile;

	MultipleTCPSocketListener *multiUserListener;
	bool running;
	map<string, User*> usersMap; // map of logged in users - string refers to user name
	map<string, ChatRoom*> chatRoomsMap; // map of logged in rooms - string refers to chat room name

/* this class will holds all the parameters that will be used in all other classes
 * that are part of the server system
 *
 * the class will contain methods that are not "too specific enough to be in other classes"
 */
public:
	virtual ~ServerInterface() {}

	virtual int  fileCountUsers() = 0 ; 	       // The method responsible to check if a given user is active
	virtual void readFromFile(User * user) = 0;    // The method responsible to display the users from the text file
	virtual void getRoomUsers(User * user) = 0;    // The method responsible to display the connected users from a given room
	virtual void getUsers(User * user) = 0;        // The method responsible to display the users in the text file
	virtual void getRoomByUser(User * user) = 0;   // The method responsible to display the rooms list
	virtual void getRoom(User * user) = 0; 	       // The method responsible to display room names (depends if the client or the server call it)
	virtual void getActiveUsers(User * user) = 0;  // The method responsible to display connected users
	virtual bool isConnected(string username) = 0; // check if the user exists in users map
};

} /* namespace npl */

#endif /* SERVERINTERFACE_H_ */
