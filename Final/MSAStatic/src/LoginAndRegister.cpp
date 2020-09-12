/*
 * LoginAndRegister.cpp
 *
 *
 * Author: Nati & Eli
 */
#include "LoginAndRegister.h"

/**
 * Constructor
 */
Login::Login(ServerManager* serverManager)
{
	listener = NULL;
	sm = serverManager;
	running = true;
	start();
	_loginFile  = "Users.txt";
}

/**
 * Run method
 */
void Login::run()
{
	TCPSocket* socket = NULL;
	int command;
	string userName;
	string password;
	while(running == true)
	{
		delete (listener);
		listener = new MultipleTCPSocketListener();
		listener->add(peers);

		socket = listener->listen(2);
		if (socket == NULL){
			continue;
		}
		command = socket->readCommand();
		switch (command)
		{
		case LOGIN_REQUEST:
			userName =  socket->readMsg();
			password =  socket->readMsg();
			if(isUserInFile(userName, password) == true)
			{
				if (sm->isConnected(userName))
				{
					socket->writeCommand(LOGIN_REQUEST_DENIED);
				}
				else
				{
					sm->userAdd(socket, userName);
					peers.erase(socket->destIpAndPort());
					socket->writeCommand(LOGIN_REQUEST_APPROVED);
				}
			}
			else
			{
				socket->writeCommand(LOGIN_REQUEST_DENIED);
			}
			break;
		case REGISTRATION_REQUEST:
			userName =  socket->readMsg();
			password =  socket->readMsg();
			if (isUserSignUp(userName,password) == true)
				socket->writeCommand(REGISTRATION_REQUEST_APPROVED);
			else
				socket->writeCommand(REGISTRATION_REQUEST_DENIED);
			break;
		case EXIT:
			peers.erase(socket->destIpAndPort());
			break;
		}
	}
}

/**
 * The method responsible to add peer to the login map
 */
void Login::addPeer (TCPSocket* peer)
{
	peers[peer->destIpAndPort()] = peer;
}

/**
 * Destructor - closing all the sockets in the map
 */
Login::~Login()
{
	running = false;

	for (map<string,TCPSocket*>::iterator iter = peers.begin(); iter != peers.end(); iter++)
	{
		iter->second->close();
	}
	waitForThread();
}

/**
 * The method responsible to search a specific username in the text file (Users.txt)
 */
bool Login::isUserInFile(string userName,string password)
{
	string temp;
	fstream loginFile;
	loginFile.open(_loginFile,ios::in|ios::out|ios::binary);

	if(loginFile.is_open() == true){
		while (!loginFile.eof())
		{
		  getline (loginFile,temp);
		  if (temp == userName+string(" ") +password)
			  return true;
		}
		loginFile.close();
   }
   else
   {
	   cout <<"ERROR, file cannot be opened" << endl;
   }
		return false;
}

/**
 * The method responsible to signup
 */
bool Login::isUserSignUp(string userName,string password)
{
	string temp;
	string userFromFile;
	fstream loginFile;
	loginFile.open(_loginFile,ios::in|ios::out|ios::binary);

	if (!loginFile.is_open()){ // if the file couldn't be opened, return false
		   cout <<"Error - could not open file" << endl;
		return false;
	}

	while ( !loginFile.eof() ) // while the file has not ended
	{
		getline (loginFile,temp);
		userFromFile = temp.substr(0, temp.find(" "));

		if (userFromFile == userName) // if user exists in file, return false
		{
		    loginFile.close();
			return false;
		}
	}
    loginFile.close();

	ofstream usersFile; // if the user is not exist in loginFile, then add him to the loginFile
	usersFile.open(_loginFile,ios::app);
	usersFile<<userName+string(" ")+password<<endl;
	usersFile.close();
	return true;
}

/**
 * Constructor
 */
Connection::Connection(Login* registration) {

	connectedUser = registration;
	running = true;
	clientSocket = new TCPSocket(MSNGR_PORT);
	start();
}


/**
 * Run method that add users to the peer list
 */
void Connection::run()
{
	TCPSocket* temp;
	while (running)
	{
		temp = clientSocket->listenAndAccept();
		if(temp == NULL)
			break;
		connectedUser->addPeer(temp);
		if (temp->destIpAndPort()!= "0.0.0.0:0" ){
			cout << "A new connection has been established with the peer, IP: "<< temp->destIpAndPort()<< endl;
		}
	}
	cout << "Server has been closed" << endl;
}

/**
 * Destructor
 */
Connection::~Connection() {
	running = false;
	clientSocket->close();
	waitForThread();
}

