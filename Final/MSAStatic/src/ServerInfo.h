/*
 * ServerInfo.h
 *
 *
 * Author: Nati & Eli
 */

#ifndef INFO_H_
#define INFO_H_


#include "ServerInterface.h"


using namespace std;
namespace npl {
/**
 * This class will holds the methods that display to the screen that are not depends on variable
 */
class ServerInfo: public ServerInterface {
public:
	ServerInfo(){}

	bool isConnected(string username);                  // The method responsible to check if a given user is active

	void printSessions(); 	                            // The method responsible to print all the users in a session
	void printUsers(); 	                                // The method responsible to print the users from the text file (registered users)
	void printActiveUsers(); 	                        // The method responsible to print all the active users in the application
	void printRooms(); 	                                // The method responsible to print all the active rooms
	void printUsersInSpecificRoom(string ChatRoomName); // The method responsible to print the users in a given room

	int  fileCountUsers() ; 	                        // Giving the numbers of users from the file (Users.txt)
	void readFromFile(User* user);                      // The method responsible to display the users from the text file
	void getRoomUsers(User* user); 	                    // The method responsible to display the connected users from a given room
	void getUsers(User* user);                          // The method responsible to display the users in the text file
	void getRoomByUser(User* user); 	                // The method responsible to display the rooms list
	void getRoom(User* user); 	                        // The method responsible to display room names (depends if the client or the server call it)
	void getActiveUsers(User* user); 	                // The method responsible to display connected users

	virtual ~ServerInfo(){}
};

} /* namespace npl */

#endif /* INFO_H_ */
