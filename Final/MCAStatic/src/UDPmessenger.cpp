/*
 * UDPmessenger.cpp
 *
 *
 * Author: Nati & Eli
 */
#include "UDPmessenger.h"

/**
 * Constructor
 */
UDPmessenger::UDPmessenger(int port):clientSocket(port)
{
	running = NULL;
	start();
}

/**
 * The method responsible of reading incoming messages from the socket, it runs in a separate thread
 */
void UDPmessenger::run()
{
	running = true;
	char buffer[SIZE];
	while(running)
	{
		for(int i = 0;i < SIZE; i++, buffer[i] = 0);
		clientSocket.recv(buffer,SIZE);
		cout << buffer << endl;
	}
}

void UDPmessenger::send(string msg,string ip, int port)
{
	clientSocket.sendTo(msg,ip,port);
}

/**
 * Destructor
 */
UDPmessenger::~UDPmessenger() {
	running = false;
	clientSocket.close();
	waitForThread();
}
