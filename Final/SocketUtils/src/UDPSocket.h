/*
 * UDPSocket.h
 *
 *
 *
 */
#ifndef UDPSOCKET_H_
#define UDPSOCKET_H_

#include <netinet/in.h>
#include <inttypes.h>
#include <strings.h>
#include <stdio.h>
#include <iostream>
#include "Socket.h"

using namespace std;
namespace npl{

class UDPSocket : public Socket{
	struct sockaddr_in from;

public:
	UDPSocket(int port);
	int recv(char* buffer, int length);
	int sendTo(const string& msg, const string& ip, int port);
	int reply(const string& msg);
	void close();
	string fromAddr();
};

}
#endif /* UDPSOCKET_H_ */
