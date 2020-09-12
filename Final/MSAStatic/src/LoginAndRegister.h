/*
 * LoginAndRegister.h
 *
 *
 * Author: Nati & Eli
 */
#ifndef LOGINANDREGISTER_H_
#define LOGINANDREGISTER_H_

#include <map>
#include <string>
#include "MThread.h"
#include "TCPSocket.h"
#include "MultipleTCPSocketListener.h"
#include "TCPMessengerProtocol.h"
#include "ServerManager.h"

using namespace std;
using namespace npl;
/**
 * The class handles the login and registration requests
 */

class Login: public MThread
{
	const char* _loginFile;
	map<string, TCPSocket*> peers;
	MultipleTCPSocketListener* listener;
	ServerManager* sm;
	bool running;

	bool isUserInFile(string userName,string password); // The method responsible to search a specific username in the text file (Users.txt)
	bool isUserSignUp(string userName,string password); // The method responsible to signup

public:
	Login(ServerManager* serverManager);                // Constructor
	void run();                                         // Run method
	void addPeer(TCPSocket* peer);                      // The method responsible to add peer to the login map
	virtual ~Login();                                   // Destructor - closing all the sockets in the map
};


class Connection: public MThread
{
	Login* connectedUser;
	TCPSocket * clientSocket;
	bool running;

public:
	Connection(Login* registration);                    // Constructor
	void run();                                         // Run method that add users to the peer list
	virtual ~Connection();                              // Destructor
};

#endif /* LOGINANDREGISTER_H_ */
