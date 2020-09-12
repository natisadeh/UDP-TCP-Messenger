/*
 * TCPSocket.h
 *
 *
 *
 */
#ifndef TCPSOCKET_H_
#define TCPSOCKET_H_

#include <netinet/in.h>
#include <inttypes.h>
#include <strings.h>
#include <stdio.h>
#include <iostream>
#include "Socket.h"
using namespace std;

namespace npl{

class TCPSocket:public npl::Socket{


private:
	/**
	 * private constructor to create a secondary server socket to communicate with a remote peer
	 */
	TCPSocket(int connected_sock,struct sockaddr_in serverAddr,struct sockaddr_in peerAddr);

public:

	TCPSocket(int port);
	TCPSocket(const string& peerIp, int port);
	TCPSocket* listenAndAccept();
	int recv(char* buffer, int length);
	int send(const string& msg);
	int send(const char* buff,int len);
	void close();
	string fromAddr();
	string destIpAndPort();
	int getSocketFid();
	int readCommand();
	string readMsg();
	void writeMsg(string msg);
	void writeCommand(int command);

	int socket();

};
}

#endif
