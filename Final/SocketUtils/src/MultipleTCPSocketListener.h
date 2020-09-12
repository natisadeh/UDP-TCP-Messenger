/*
 * MultipleTCPSocketListener.h
 *
 *
 *
 */
#ifndef MULTIPLETCPSOCKETLISTENER_H_
#define MULTIPLETCPSOCKETLISTENER_H_

#include <iostream>
#include <stdio.h>
#include <vector>
#include <map>
#include <iterator>
#include <sys/time.h>
#include <sys/types.h>
#include <unistd.h>
#include "TCPSocket.h"

using namespace std;
namespace npl {

class MultipleTCPSocketListener {

	typedef vector<TCPSocket*> tSockets;
		vector<TCPSocket*> sockets;

	public:
		/**
		 * add socket to listen to
		 */
		void add(TCPSocket* socket);
		void add(map<string,TCPSocket*> socketMap);
		TCPSocket* listen(int timeout);
};

} /* namespace npl */

#endif /* MULTIPLETCPSOCKETLISTENER_H_ */
