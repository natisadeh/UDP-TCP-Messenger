/*
 * Socket.h
 *
 *
 *
 */
#ifndef SOCKET_H_
#define SOCKET_H_


#include <netinet/in.h>
#include <inttypes.h>
#include <strings.h>
#include <stdio.h>
#include <iostream>


using namespace std;

namespace npl{
class Socket {
protected:
	struct sockaddr_in serverAddr;
	struct sockaddr_in peerAddr;
	int socket_fd;

public:

	virtual ~Socket(){}

};
}
#endif /* SOCKET_H_ */
