/*
 * User.cpp
 *
 *
 * Author: Nati & Eli
 */
#include "User.h"

/**
 * Constructor
 */
User::User(string name, TCPSocket* sock)
{
	socket = sock;
	userName = name;

	string tempPort;
	istringstream liness( socket->destIpAndPort() );

	getline( liness, userIP, ':' );
	getline( liness, tempPort,  ':' );
	port= atoi(tempPort.c_str());

	isChatRoom = false;
	isSession = false;
	chatRoom = NULL;
	otherUser = NULL;
}

TCPSocket* User::getSocket()
{
	return socket;
}

/**
 * Boolean method that check if the user is in session or chat
 */
bool User::isInSessionOrChat()
{
	return (isInChatRoom() == true || isInSession() == true);
}

/**
 * Boolean method that check if the user is in chat room
 */
bool User::isInChatRoom()
{
	return isChatRoom;
}

/**
 * Boolean method that check if the user is in session
 */
bool User::isInSession()
{
	return isSession;
}

/**
 * The method responsible to connect between to peers (it called from the ServerManager)
 */
void User::connectBetweenUsers(User* partner)
{
	isSession = true;
	otherUser = partner;

}

/**
 * Boolean method that responsible to close session
 */
bool User::closeSession(bool flag)
{
	if (isInSession() == false){
		return true;
	}

	if (flag == true){
		otherUser->closeSession(false);
	}

	writeCommand(SESSION_CLOSED);
	isSession = false;
	otherUser = NULL;
	return true;
}

/**
 * The method responsible to confirm chat room login
 */
void User::chatRoomConfirmation(ChatRoom* room)
{
	isChatRoom = true;
	chatRoom = room;
}

/**
 * The method responsible to disconnect user from chat room and erase from the vector (in ChatRoom class)
 */
void User::disconnectFromChatRoom(bool flag)
{
	if(isInChatRoom())
	{
		if (flag == false)
			chatRoom->userLogout(this);
		writeCommand(CHAT_ROOM_USER_LEFT); // message to the client
		chatRoom = NULL;
		isChatRoom = false;
	}

}


int User::readCommand()
{
	return socket->readCommand();
}

void User::writeCommand(int command)
{
	socket->writeCommand(command);
}

string User::readMsg()
{
	return socket->readMsg();
}

void User::writeMsg(string msg)
{
	socket->writeMsg(msg);
}

string User::getDestandport()
{
	return socket->destIpAndPort();
}

string User::getUsername()
{
	return userName;
}

string User::getIP()
{
	return userIP;
}

int User::getPort()
{
	return port;
}

ChatRoom* User::getChatRoom()
{
	return chatRoom;
}

User::~User() {
	delete(socket);
}
