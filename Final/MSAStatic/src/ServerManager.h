/*
 * ServerManager.h
 *
 *
 * Author: Nati & Eli
 */
#ifndef SERVERMANAGER_H_
#define SERVERMANAGER_H_

#include "ServerInfo.h"

class ServerManager: public ServerInfo {


	/* this class will holds the actual connections methods , such as:
	 * add
	 * delete
	 * login chat room
	 * enter chat room
	 * create session
	 * exit
	 */
public:
	ServerManager();

	void openSession(User* first, User* second);       // The method responsible to create a session between two peers
	void run();                                        // Run method
	bool userAdd(TCPSocket*  socket, string userName); // The method responsible to add user to he map
    void serverExit(User* user);                       // The method responsible to disconnect the client from the server and erase from the map
	void chatRoomCreate(User* user); 	               // The method responsible to create a chat room
	void chatRoomDelete(User* user); 	               // The method responsible to delete chat room and erase it from the map
	void chatRoomEnter(User* user); 	               // The method responsible to enter a chat room

	virtual ~ServerManager();


};

#endif /* SERVERMANAGER_H_ */
