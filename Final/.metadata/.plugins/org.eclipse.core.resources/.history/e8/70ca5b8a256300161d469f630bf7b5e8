/*
 * ChatRoom.h
 *
 *
 * Author: Nati & Eli
 */
#ifndef CHATROOM_H_
#define CHATROOM_H_

#include <vector>
#include "User.h"

class User;

class ChatRoom {
	string roomName;
	vector<User*> roomUsers;
	User* roomOwner;

	void usersUpdate();                 // The method responsible to give information of the users in all the rooms

public:
	ChatRoom(User* owner, string room); // Constructor

	bool userAdd(User* user);           // The method responsible to add users to given room (add him to the vector)
	bool userLogout(User* user);        // The method responsible to logout user from the chat room and erasing him for the users vector

	User* getOwner();                   // Return roomOwner
	int userSendList(User* user);       // The method responsible to send the number of users from the vector to the client
	void printUsers();                  // The method responsible to print the username from a room (we will call it from the ServerInfo)

	virtual ~ChatRoom();                // Destructor

};

#endif /* CHATROOM_H_ */
