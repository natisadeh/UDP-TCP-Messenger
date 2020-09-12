/*
 * ClientManager.h
 *
 *
 * Author: Nati & Eli
 */
#ifndef CLIENTMANAGER_H_
#define CLIENTMANAGER_H_

#include "ClientInterface.h"
#include "ClientInfo.h"
#include "Colors.h"

class ClientManager : public ClientInfo {

public:
	ClientManager();                                                // Constructor

	bool chatRoomDelete(string msg);                                // The method responsible to delete the chat room
	bool chatRoomCreate(string name);                               // The method responsible is to create a chat room.
	bool chatRoomEnter(string roomName);                            // Entering existing chat room
	bool leaveRoomOrCloseSession();                                 // The method responsible leaving a room or close a session
	bool sendMsg(string msg);                                       // The method responsible to send messages between clients in open session or in a chat room
	bool connectToServer(string ip,int port);                       // Connecting user to server
	bool peersSession(string chatSideBName);                        // The method responsible to open session between two users


	void run();                                                     // Run method
	void chatRoomUpdate();                                          // Updating information in a chat room
	void chatRoomAddUser(string username, string IP, int port);     // Add users to the chat room vector.
	void userLogin(string username,string password,int cmd);        // The method responsible of the login to the server
	void userRegister(string username,string password,int cmd); 	// The method register a new user to server
	void disconnect();                                              // The method responsible to shutdown everything...

	virtual ~ClientManager();                                       // Destructor
};

#endif /* CLIENTMANAGER_H_ */
