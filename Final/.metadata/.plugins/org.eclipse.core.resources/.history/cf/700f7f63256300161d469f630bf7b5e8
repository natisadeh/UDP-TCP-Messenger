/*
 * ClientManager.cpp
 *
 *
 * Author: Nati & Eli
 */
#include "ClientManager.h"

/**
 * Constructor
 */
ClientManager::ClientManager() {
	isLogin = false;
	isSessionActive = false;
	isRoomActive = false;
	isConnected = false;
	serverSocket = NULL;
	userName.clear();
}

/**
 * Run method
 */
void ClientManager::run()
{
	string message;
	int partnerPort;
	int command;
	running = true;

	while (running)
	{
		command = serverSocket->readCommand();
		if (!command)
			continue;
		switch(command)
		{
			case SESSION_ESTABLISHED:
				/**
				 * Updating the other user info
				 */
				otherSide.name = serverSocket->readMsg();
				otherSide.IP = serverSocket->readMsg();
				otherSide.port = serverSocket->readCommand();

				/**
				 * Creating UDP session
     			 */
				partnerPort = serverSocket->readCommand();
				UDPmsgr = new UDPmessenger(partnerPort);
				isSessionActive = true;
				cout << BOLD(FGRN("You have opened a UDP session with: ")) << otherSide.name << endl;
				break;

			case SESSION_REFUSED:
				message = serverSocket->readMsg();
				cout << BOLD(FRED("Session denied")) << endl;
				break;

			case SESSION_CLOSED:
				otherSide.Clean();
				isSessionActive = false;
				delete(UDPmsgr);
				cout << BOLD(FMAG("Closing session")) << endl;
				break;

			case CHAT_ROOM_CREATE:
				cout << BOLD(FGRN("A new chat room has been created")) << endl;
				break;

			case CHAT_ROOM_CREATE_DENIED:
				cout << BOLD(FRED("You are trying to open a room that already exist!")) << endl;
				break;
			case CHAT_ROOM_USER_JOIN_DENIED:
				cout << BOLD(FRED("The room is not exist...")) << endl;
				break;

			case CHAT_ROOM_USER_JOIN:
				partnerPort = serverSocket->readCommand();
				UDPmsgr = new UDPmessenger(partnerPort);
				isRoomActive = true;
				cout << BOLD(FBLU("You have joined the chat room")) << endl;
				break;

			case CHAT_ROOM_USER_LEFT:
				sendMsg (BOLD(FBLU("has left the chat room")));
				chatRoomRemoveUser();
				cout<<BOLD(FBLU("You have left the room"))<<endl;
				break;

			case CHAT_ROOM_UPDATE:
				chatRoomUpdate();
				break;

			case CHAT_ROOM_CLOSE:
				cout<<BOLD(FRED("Closing chat room"))<<endl;
				break;

			case CHAT_ROOM_CLOSE_DENIED:
				cout<<BOLD(FRED("You have no permission to close the room"))<<endl;
				break;

			case CHAT_ROOM_NOT_EXIST:
				cout<<BOLD(FRED("Room is not exist"))<<endl;
				break;
			case CHAT_ROOM_EMPTY:
				cout<<BOLD(FRED("No users in the room"))<<endl;
				break;

			case LIST_USERS:
				printUsersList();
				break;

			case LIST_CONNECTED_USERS:
				printConnectedUsers();
				break;

			case LIST_ROOMS:
				printActiveRooms();
				break;

			case LIST_CONNECTED_USERS_IN_ROOM:
				printConnectedUsers();
				break;
		}
	}
}

/**
 * Connecting user to server
 */
bool ClientManager::connectToServer(string ip, int port)
{
	if(serverSocket != NULL)
		return false;
	serverSocket = new TCPSocket(ip,port);
	isConnected = true;
	return true;
}

/**
 * The method register a new user to server
 * The method check if the user is already logged in, username taken or not connected to the server
 * else it creates a new user to the server
 */
void ClientManager::userRegister(string username,string password,int cmd)
{
	if (isLogin)
	{
		cout << BOLD(FRED("You are already logged in to the server!")) << endl;
		return;
	}

	int response;
	if(serverSocket)
	{
		serverSocket->writeCommand(cmd);
		serverSocket->writeMsg(username);
		serverSocket->writeMsg(password);
		response = serverSocket->readCommand();

		if (response == REGISTRATION_REQUEST_APPROVED)
		{
			cout<<BOLD(FGRN("Registration successfully with the user: "))<<username<<endl;
		}
		else if(response==REGISTRATION_REQUEST_DENIED)
		{
			cout<<BOLD(FRED("Registration has failed, username is already taken"))<<endl;
		}
	}
	else
	{
		cout<<BOLD(FRED("You have to connect the server before register"))<<endl;
	}
}

/**
 * The method responsible of the login to the server
 * The method check if the user already logged in
 */
void ClientManager::userLogin(string username,string password,int cmd)
{
	if (isLogin == true)
	{
		cout << BOLD(FRED("You are already logged in to the server")) << endl;
		return;
	}

	int answer;
	if(serverSocket)
	{
		serverSocket->writeCommand(cmd);
		serverSocket->writeMsg(username);
		serverSocket->writeMsg(password);
		answer = serverSocket->readCommand();

		if(answer == LOGIN_REQUEST_APPROVED)
		{
			userName = username;
			isLogin = true;
			start();
			cout << BOLD(FGRN("You are logged in as ")) << username << endl;
		}
		else if(answer == LOGIN_REQUEST_DENIED)
		{
			cout << BOLD(FRED("Login request denied")) << endl;
		}
	}
	else
	{
		cout << BOLD(FRED("Server is offline")) << endl;
	}
}

/**
 * The method responsible to open session between two users
 */
bool ClientManager::peersSession(string secondUser)
{
	if (serverSocket == NULL) // Check if the user connceted to the server
	{
		cout << BOLD(FRED("Please connect to the server")) << endl;
		return false;
	}
	else if (isLogin == false) // Check if the user is logged in
	{
		cout << BOLD(FRED("You are not logged in to the server")) << endl;
		return false;// update the chat rooms according to the given information by the server
	}
	else if(isInChat() == true) // Check if the user in chat or open session
	{
		cout << BOLD(FRED("You already in a chat room or open session")) << endl;
		return false;
	}
	else if(secondUser == userName) // Check if the user trying to open session with himself
	{
		cout << BOLD(FRED("You can't open a session with yourself")) << endl;
		return false;
	}
	else // Open session with the given username
	{
		serverSocket->writeCommand(SESSION_CREATE);
		serverSocket->writeMsg(secondUser);
		return true;
	}

}

/**
 * The method responsible to send messages between clients in open session or in a chat room
 */
bool ClientManager::sendMsg(string msg)
{
	if(isSessionActive == true)
	{
		UDPmsgr->send( string(">[")+userName+string("]") + msg,otherSide.IP,otherSide.port);
		return true;
	}
	else if (isRoomActive == true)
	{
		std::vector<OtherSide*>::iterator iter = chatUsers.begin();
		std::vector<OtherSide*>::iterator enditer = chatUsers.end();

		while (iter != enditer)
		{
			UDPmsgr->send(string(">[")+userName+string("] ") + msg,(*iter)->IP,(*iter)->port);
			iter++;
		}
		return true;
	}
	return false;
}

/**
 * The method responsible is to create a chat room.
 */
bool ClientManager::chatRoomCreate(string roomName)
{
	if(isInChat() == true) // Check if the user is already in a room or an open session
	{
		cout << BOLD(FRED("You are already in a chat room or in an open session")) << endl;
		return false;
	}
	else if (isLogin == false) // Check if the user is logged in
	{
		cout << BOLD(FRED("You have to login first")) << endl;
		return false;
	}
	else if (serverSocket== NULL) // Check if the user is not logged
	{
		cout << BOLD(FRED("You are not connected to the server")) << endl;
		return false;
	}
	else
	{
	    serverSocket->writeCommand(CHAT_ROOM_CREATE);
	    serverSocket->writeMsg(roomName);
	    return true;
	}
}

/**
 * Entering existing chat room
 */
bool ClientManager::chatRoomEnter(string roomName)
{
	if (isInChat() == true) // Check if the user is already in a room or an open session
	{
		cout << BOLD(FRED("You are already in a chat room or in an open session")) << endl;
		return false;
	}
	else if(isLogin == false) // Check if the user is logged in
	{
		cout << BOLD(FRED("You have to login first")) << endl;
		return false;
	}
	else if (serverSocket == NULL) // Check if the user is not logged
	{
		cout << BOLD(FRED("You are not connected to the server")) << endl;
		return false;
	}
	else
	{
		serverSocket->writeCommand(CHAT_ROOM_USER_JOIN);
		serverSocket->writeMsg(roomName);
		return true;
	}
}

/**
 * The method responsible to delete the chat room
 * Only the owner have permission to do delete the chat room
 */
bool ClientManager::chatRoomDelete(string name)
{
	if(isLogin == false) // Check if the user is logged in
	{
		cout << BOLD(FRED("You have to login first")) << endl;
		return false;
	}
	else if (serverSocket == NULL) // Check if the user is not logged
	{
		cout << BOLD(FRED("You are not connected to the server")) << endl;
		return false;
	}
	else
	{
		serverSocket->writeCommand(CHAT_ROOM_CLOSE);
		serverSocket->writeMsg(name);
		return true;
	}

}

/**
 * The method responsible leaving a room or close a session
 */
bool ClientManager::leaveRoomOrCloseSession()
{
	if (isRoomActive == true)
	{
		serverSocket->writeCommand(CHAT_ROOM_USER_LEFT);
		return true;
	}

    if (isSessionActive == true)
	{
		serverSocket->writeCommand(SESSION_CLOSED);
		return true;
	}

	return false;
}

/**
 * Add users to the chat room vector.
 */
void ClientManager::chatRoomAddUser(string roomate, string IP, int port)
{
	OtherSide *temp= new OtherSide();
	temp->name =roomate;
	temp->IP = IP;
	temp->port = port;
	chatUsers.push_back(temp);
}

/**
 * The method responsible to shutdown everything...
 */
void ClientManager::disconnect()
{
	leaveRoomOrCloseSession();
	serverSocket->writeCommand(EXIT);
	userName.clear();
	running = false;
	isLogin = false;
	isConnected = false;
	serverSocket = NULL;
}

/**
 * Updating information in a chat room
 */
void ClientManager::chatRoomUpdate()
{
	isRoomActive = true;
	clearOtherSideVector();

	roomName = serverSocket->readMsg();
	int membersCounter = serverSocket->readCommand();
	for (int i = 0 ; i< membersCounter;i++)
	{
		string user = serverSocket->readMsg();
		string ip = serverSocket->readMsg();
		int port = serverSocket->readCommand();
		chatRoomAddUser(user,ip,port);
	}

}

/**
 * Destructor
 */
ClientManager::~ClientManager() {
	running = false;
}
