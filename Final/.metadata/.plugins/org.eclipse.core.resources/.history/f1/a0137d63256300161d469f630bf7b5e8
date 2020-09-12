/*
 * ClientInfo.cpp
 *
 *
 * Author: Nati & Eli
 */

#include "ClientInfo.h"

using namespace std;
using namespace npl;


/**
 * Clearing the otherSide's vector
 */
void ClientInfo::clearOtherSideVector()
{
	std::vector<OtherSide*>::iterator iter = chatUsers.begin();
	std::vector<OtherSide*>::iterator enditer = chatUsers.end();

	while (iter != enditer)
	{
		delete(*iter);
		iter++;
	}
	chatUsers.clear();
}

/**
 * Boolean method that check if a room is active or a session is active
 */
bool ClientInfo::isInChat()
{
	return isRoomActive || isSessionActive;
}

/**
 * Boolean method that check if a socket entered the server
 */
bool ClientInfo::isConnectedToServer() const
{
	return isConnected;
}

/**
 * Method that responsible to remove a client from the chat room
 */
void ClientInfo::chatRoomRemoveUser()
{
	isRoomActive = false;
	clearOtherSideVector();
	delete(UDPmsgr);
}

/**
 * The method responsible to print connected users to the screen
 */
void ClientInfo::printConnectedUsers()
{
	int count = 0;
	int numOfUsers = serverSocket->readCommand();

	for(int i=0 ; i < numOfUsers ; i++)
	{
		if (i==0){
			cout << BOLD(FBLU("Current users online: ")) << endl;
		}
		cout << (i+1) << ") " << serverSocket->readMsg() << endl;
		count++;
	}

	if(count == 0 && serverSocket == NULL)
	{
		cout << BOLD(FRED("There are no connected users")) << endl;
	}
}

/**
 * The method responsible to print the status of the client
 */
void ClientInfo::printStatus()
{
	cout << BOLD(FBLU("Current status: ")) << endl;

	if (serverSocket != NULL){
		cout << BOLD(FMAG("You are connected to the server")) << endl;
	}else{
		cout << BOLD(FMAG("You are ")) << UNDL(FRED("NOT")) << BOLD(FMAG(" connected to the server")) <<  endl;
	}
	if (isLogin == true){
		cout << BOLD(FMAG("You are logged in to the server")) << endl;
	}else{
		cout << BOLD(FMAG("You are ")) << UNDL(FRED("NOT")) << BOLD(FMAG(" logged in to the server")) <<  endl;
	}
	if (isSessionActive == true){
		cout << BOLD(FMAG("You are in a session")) << endl;
	}else{
		cout << BOLD(FMAG("You are ")) << UNDL(FRED("NOT")) << BOLD(FMAG(" in a session")) <<  endl;
	}
	if (isRoomActive == true){
		cout << BOLD(FMAG("You are in a chat room: ")) << roomName <<  endl;
	}else{
		cout << BOLD(FMAG("You are ")) << UNDL(FRED("NOT")) << BOLD(FMAG(" in a chat room")) <<  endl;
	}
}

/**
 * The method responsible to print the active rooms
 */
void ClientInfo::printActiveRooms()
{
	int numOfRooms = serverSocket->readCommand();

	if(numOfRooms > 0)
	{
		cout << BOLD(FBLU("Current active rooms: ")) << endl;
		for(int i = 0 ; i < numOfRooms ;i++)
		{
			cout << (i+1) << ") " << serverSocket->readMsg() << endl;
		}
	}
	else
		cout << BOLD(FRED("There are no active rooms")) << endl;
}

/**
 * The method responsible to printing the users list
 */
void ClientInfo::printUsersList()
{
	int numOfUsers = serverSocket->readCommand();

	cout << BOLD(FBLU("Users list:")) << endl;
	for(int i=0 ; i < numOfUsers ; i++)
	{
		cout << (i+1) << ") " << serverSocket->readMsg() << endl;
	}
}

/**
 * Calling to the actual printing method, only connected user (including logged in) can activate it.
 */
void ClientInfo::getConnectedUsersList()
{
	if (serverSocket == NULL || isLogin == false)
	{
		cout << BOLD(FRED("You are not connected or not logged in to the server")) << endl;
		return;
	}
	serverSocket->writeCommand(LIST_CONNECTED_USERS);
}

/**
 *  Calling to the actual printing method, only connected user (including logged in) can activate it.
 */
void ClientInfo::getUsersList()
{

	if (serverSocket == NULL || isLogin == false)
	{
		cout << BOLD(FRED("You are not connected or not logged in to the server")) << endl;
		return;
	}
	serverSocket->writeCommand(LIST_USERS);
}

/**
 *  Calling to the actual printing method, only connected user (including logged in) can activate it.
 */
void ClientInfo::getRoomList()
{
	if (serverSocket == NULL || isLogin == false)
	{
		cout << BOLD(FRED("You are not connected or not logged in to the server")) << endl;
		return;
	}
	serverSocket->writeCommand(LIST_ROOMS);
}

/**
 * Calling to the actual printing method, only connected user (including logged in) can activate it.
 */
void ClientInfo::getUsersInSpecificRoom(string roomName)
{
	if (serverSocket == NULL || isLogin == false)
	{
		cout << BOLD(FRED("You are not connected or not logged in to the server")) << endl;
		return;
	}
	serverSocket->writeCommand(LIST_CONNECTED_USERS_IN_ROOM);
	serverSocket->writeMsg(roomName);
}

