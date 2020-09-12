/*
 * User.h
 *
 *
 * Author: Nati & Eli
 */
#ifndef USER_H_
#define USER_H_

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <stdio.h>
#include <stdlib.h>

#include "TCPSocket.h"
#include "ChatRoom.h"
#include "TCPMessengerProtocol.h"

using namespace npl;
class ChatRoom;

class User{
	string userName;
	string userIP;
	int port;

	TCPSocket* socket;
	User* otherUser;
	ChatRoom* chatRoom;

	bool isChatRoom;
	bool isSession;

public:
	User(string name, TCPSocket* sock);        // Constructor

	bool isInSessionOrChat();                  // Boolean method that check if the user is in session or chat
	bool isInSession();                        // Boolean method that check if the user is in session
	bool isInChatRoom();                       // Boolean method that check if the user is in chat room
	bool closeSession(bool flag);              // Boolean method that responsible to close session

	void connectBetweenUsers(User* user);      // The method responsible to connect between to peers (it called from the ServerManager)
	void chatRoomConfirmation(ChatRoom* room); // The method responsible to confirm chat room login
	void disconnectFromChatRoom(bool flag);    // The method responsible to disconnect user from chat room and erase from the vector (in ChatRoom class)

	string getUsername();                      // get userName
	string getIP();                            // get IP
	int getPort();                             // get Port
	ChatRoom* getChatRoom();                   // get chatRoom

	TCPSocket* getSocket();                    // get Socket
	string getDestandport();                   // get IP and Port
	int readCommand();                         // Read command
	string readMsg();                          // Read message
	void writeMsg(string msg);                 // Write message
	void writeCommand(int command);            // Write Command

	virtual ~User();                           // Destructor
};

#endif /* USER_H_ */
