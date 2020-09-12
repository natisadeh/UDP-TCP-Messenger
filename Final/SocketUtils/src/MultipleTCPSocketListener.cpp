/*
 * MultipleTCPSocketListener.cpp
 *
 *
 *
 */
#include "MultipleTCPSocketListener.h"

namespace npl {

void MultipleTCPSocketListener::add(TCPSocket* socket){
	sockets.push_back(socket);

}

void MultipleTCPSocketListener::add(map<string,TCPSocket*> socketMap)
{
	std::map<string,TCPSocket*>::iterator iter = socketMap.begin();
	std::map<string,TCPSocket*>::iterator enditer = socketMap.end();

	while (iter != enditer)
	{
		sockets.push_back(iter->second);
		iter++;
	}
}

TCPSocket* MultipleTCPSocketListener::listen(int timeout){
	fd_set set;
	int nfd = 0;
	FD_ZERO(&set);
	tSockets::iterator iter = sockets.begin();
	for(;iter!= sockets.end();iter++){
		TCPSocket* sock = *iter;
		int fd = sock->socket();
		FD_SET(fd,&set);
		if (fd >= nfd){
			nfd = fd+1;
		}
	}

	int rc;
	if(timeout > 0){
		struct timeval timet;
		timet.tv_sec = timeout;
		timet.tv_usec = 0;
		rc = select(nfd, &set,NULL,NULL,&timet);
	}else{
		rc = select(nfd, &set,NULL,NULL,NULL);
	}
	if (rc<1){
		FD_ZERO(&set);
		return NULL;
	}

	iter = sockets.begin();
	for(;iter!= sockets.end();iter++){
		TCPSocket* sock = *iter;
		int fd = sock->socket();
		if(FD_ISSET(fd,&set)){
			FD_ZERO(&set);
			return sock;
		}
	}
	FD_ZERO(&set);
	return NULL;
}

} /*namespace npl*/

