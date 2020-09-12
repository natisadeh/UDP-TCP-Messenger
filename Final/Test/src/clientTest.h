/*
 * clientTest.h
 *
 *  Created on: Aug 15, 2016
 *      Author: user
 */

#ifndef CLIENTTEST_H_
#define CLIENTTEST_H_

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

namespace npl {

class clientTest {
public:
	clientTest();
	virtual ~clientTest();
	bool test();
};

} /* namespace npl */

#endif /* CLIENTTEST_H_ */
