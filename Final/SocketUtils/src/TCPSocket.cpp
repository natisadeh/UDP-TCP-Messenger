/*
 * TCPSocket.cpp
 *
 *
 *
 */

#include "TCPSocket.h"
#include <sys/types.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <sys/socket.h>
#include <unistd.h>
#include <string.h>

using namespace std;
using namespace npl;

TCPSocket::TCPSocket(int connected_sock,struct sockaddr_in serverAddr,struct sockaddr_in peerAddr){
	this->serverAddr =  serverAddr;
	this->peerAddr =  peerAddr;
	socket_fd = connected_sock;

}

TCPSocket::TCPSocket(int port){

	socket_fd =:: socket (AF_INET, SOCK_STREAM, 0);

	bzero((char *) &serverAddr, sizeof(serverAddr));

	serverAddr.sin_family = (short)AF_INET;
	serverAddr.sin_addr.s_addr = htonl(INADDR_ANY);
	serverAddr.sin_port = htons((u_short)port);

	printf("TCP server binding...\n");
	if (bind(socket_fd, (struct sockaddr *)&serverAddr, sizeof(serverAddr)) < 0)
	{
		perror ("Error naming channel");
	}
}


TCPSocket::TCPSocket(const string& peerIp, int port){
	socket_fd =:: socket (AF_INET, SOCK_STREAM, 0);

	bzero((char *) &peerAddr, sizeof(peerAddr));

	peerAddr.sin_family = (short)AF_INET;
	peerAddr.sin_addr.s_addr = inet_addr(peerIp.data());
	peerAddr.sin_port = htons((u_short)port);

	if (connect(socket_fd, (struct sockaddr *)&peerAddr, sizeof(peerAddr)) < 0)
	{
		perror ("Error establishing communications");
		::close(socket_fd);
	}
}


TCPSocket* TCPSocket::listenAndAccept(){
	int rc = listen(socket_fd, 1);
	if (rc<0){
		return NULL;
	}
	socklen_t len = sizeof(peerAddr);
	bzero((char *) &peerAddr, sizeof(peerAddr));

	int connect_sock = accept(socket_fd, (struct sockaddr *)&peerAddr, &len);
	return new TCPSocket(connect_sock,serverAddr,peerAddr);
}


int TCPSocket::recv(char* buffer, int length){
	return read(socket_fd,buffer,length);
}


int TCPSocket::send(const string& msg){
	return write(socket_fd,msg.c_str(),msg.size());
}

int TCPSocket::send(const char* buff,int len){
	return write(socket_fd,buff,len);
}

int TCPSocket::socket(){
		return socket_fd;
	}


void TCPSocket::close(){
	cout<<"closing socket"<<endl;
	shutdown(socket_fd,SHUT_RDWR);
	::close(socket_fd);
}


string TCPSocket::fromAddr(){
	return inet_ntoa(peerAddr.sin_addr);
}

string TCPSocket::destIpAndPort(){
	string str = inet_ntoa(peerAddr.sin_addr);
			str.append(":");
			char buff[10];
			sprintf(buff,"%d",ntohs(peerAddr.sin_port));
			str.append(buff);
			return str;
}

int TCPSocket::getSocketFid(){
	return socket_fd;
}


int TCPSocket::readCommand()
{
	int messagelength = 0, recived = 0;
	recived = recv((char*)&messagelength,4);
	if(!recived==4)
		return 0;
	return ntohl((uint32_t)messagelength);
}

string TCPSocket::readMsg()
{
	char rcvmsg[300];
	bzero(rcvmsg, 300);
	int recived = 0,messagelength = 0, len = 0;
	recived = recv((char*)&messagelength,4);
	if(!recived>0)
		return string("0");
	len = ntohl((uint32_t)messagelength);
	recv(rcvmsg,len);
	return string(rcvmsg);
}

void TCPSocket::writeCommand(int command)
{
	int msglen = htonl((uint32_t)command);
	send((char*)&msglen,4);
}

void TCPSocket::writeMsg(string msg)
{
	int msglen = htonl((uint32_t) msg.length());
	send((char*)&msglen,4);
	send(msg.c_str(),msg.length());
}
