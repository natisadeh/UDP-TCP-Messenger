/*
 * ChatRoom.cpp
 *
 *
 * Author: Nati & Eli
 */
#include "ChatRoom.h"

ChatRoom::ChatRoom(User* owner, string room) {
	roomOwner = owner;
	roomName = room;
}

/**
 * The method responsible to add users to given room (add him to the vector)
 */
bool ChatRoom::userAdd(User* user)
{

	// check if user exists in the chat room
	for(vector<User*>::iterator iter = roomUsers.begin(); iter != roomUsers.end(); iter++)
	{
		if ((*iter) == user)
		{
			cout << "User is already exist" <<endl;
			return false;
		}

	}

	// if the user does not exist in the vector array, add him to the vector and update
	roomUsers.push_back(user);
	usersUpdate();
	return true;
}


/**
 * The method responsible to logout user from the chat room and erasing him for the users vector
 */
bool ChatRoom::userLogout(User* user)
{
    // check if user exists
	for(vector<User*>::iterator iter = roomUsers.begin(); iter != roomUsers.end(); iter++)
	{
		if ((*iter) == user)
		{
			roomUsers.erase(iter);
			usersUpdate();
			return true;
		}
	}
	return false;
}


/**
 * Return roomOwner
 */
User* ChatRoom::getOwner()
{
	return roomOwner;
}

/**
 * The method responsible to give information of the users in all the rooms
 */
void ChatRoom::usersUpdate()
{
	// loop that will give us rooms
	for(vector<User*>::iterator iter = roomUsers.begin(); iter != roomUsers.end(); iter++)
	{
		(*iter)->writeCommand(CHAT_ROOM_UPDATE);
		(*iter)->writeMsg(roomName);
		(*iter)->writeCommand(roomUsers.size());

		// loop that will give us the info of the room users
		for(vector<User*>::iterator iter2 = roomUsers.begin(); iter2 != roomUsers.end(); iter2++)
		{
			(*iter)->writeMsg((*iter2)->getUsername());
			(*iter)->writeMsg((*iter2)->getIP());
			(*iter)->writeCommand((*iter2)->getPort());

		}
	}
}

/**
 * The method responsible to send the number of users from the vector to the client
 */
int ChatRoom::userSendList(User* user)
{
	int userCount = 0;

	user->writeCommand(roomUsers.size());
	for(vector<User*>::iterator iter = roomUsers.begin(); iter != roomUsers.end(); iter++)
	{
		user->writeMsg((*iter)->getUsername());
		userCount++;
	}
	return userCount;
}


/**
 * The method responsible to print the username from a room (we will call it from the ServerInfo)
 */
void ChatRoom::printUsers()
{
	for(vector<User*>::iterator iter = roomUsers.begin(); iter != roomUsers.end(); iter++)
	{
		cout<<(*iter)->getUsername()<<endl;
	}
}


/**
 * The destructor delete all the users from the vector...
 */
ChatRoom::~ChatRoom() {
	for(vector<User*>::iterator iter = roomUsers.begin(); iter != roomUsers.end(); iter++)
	{
		(*iter)->disconnectFromChatRoom(true);
	}
}
