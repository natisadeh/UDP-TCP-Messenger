//============================================================================
// Name        : Test.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <strings.h>
#include <string.h>
#include <map>
#include <vector>
#include "MThread.h"
#include "MultipleTCPSocketListener.h"
#include "TCPSocket.h"
#include "Socket.h"
#include "TCPMessengerProtocol.h"
#include "UDPSocket.h"
#include <iostream>
#include <fstream>
#include "ClientInfo.h"
#include "ClientInterface.h"
#include "ClientManager.h"
#include "OtherSide.h"
#include "UDPmessenger.h"
#include "ChatRoom.h"
#include "LoginAndRegister.h"
#include "ServerInfo.h"
#include "ServerInterface.h"
#include "ServerManager.h"
#include "User.h"
#include "clientTest.h"

using namespace std;

int main() {
//    ServerManager serverManager;
//    Login registration(&serverManager);
//    Connection connection(&registration);
//	ClientManager* client = new ClientManager();
//	ClientManager client;
    clientTest cli;

	if(cli.test() == true){
		cout << "TEST PASSED" << endl;
	}
	else{
		cout<<"TEST FAILED"<<endl;
	}

	return 0;
}
