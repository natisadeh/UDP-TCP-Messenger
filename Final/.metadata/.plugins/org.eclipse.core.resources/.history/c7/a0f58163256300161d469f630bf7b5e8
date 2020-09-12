/*
 * UDPmessenger.h
 *
 *
 * Author: Nati & Eli
 */
#ifndef UDPMESSENGER_H_
#define UDPMESSENGER_H_

#include "MThread.h"
#include "UDPSocket.h"

#define SIZE 1024

using namespace npl;

class UDPmessenger : public MThread {

	UDPSocket clientSocket;
	bool running;

public:
	void send(string msg,string ip, int port);
	UDPmessenger(int port);
	void run();
	virtual ~UDPmessenger();
};

#endif /* UDPMESSENGER_H_ */
