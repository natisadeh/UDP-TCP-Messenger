/*
 * ServerManager.cpp
 *
 *
 * Author: Nati & Eli
 */
#include "ServerManager.h"


ServerManager::ServerManager() {

	multiUserListener = NULL;
	running = true;
	usersFile = "Users.txt";
	start();
	cout<<"Server manager is connected"<<endl;
}

/**
 * Run method
 */
void ServerManager::run()
{
	running = true;
	User* user = NULL;
	multiUserListener = NULL;
	long command = 0;
	string temp;
	while (running == true)
	{
		if (multiUserListener != NULL)
		{
			delete (multiUserListener);
		}
		multiUserListener = new MultipleTCPSocketListener();

		// Create map of sockets (the name, socket), converting user to socket before adding to the listener
		map<string,TCPSocket*> socket;

		for (map<string,User*>::iterator iter = usersMap.begin(); iter != usersMap.end(); iter++)
		{
			socket[iter->first] = (iter->second->getSocket());
		}
		multiUserListener->add(socket);

		// Listening to to socket
		TCPSocket* readyPeer = multiUserListener->listen(2);
		if (readyPeer == NULL)
		{
			continue;
		}

		// searching for the connected peer from the map where found implement him to the user
		for (map<string,User*>::iterator iter = usersMap.begin(); iter != usersMap.end(); iter++)
		{
			if (readyPeer == iter->second->getSocket())
			{
				user = iter->second;
				break;
			}
		}

		command = user->readCommand();

		switch(command)
		{
		case SESSION_CREATE:
			temp = user->readMsg(); // getting the other user we want to open session with
			if (!usersMap[temp])
			{
				user->writeCommand(SESSION_REFUSED); // if not found session refused
				user->writeMsg(string("The user you are looking for does not exist"));
				break;
			}
			else if (usersMap[temp]->isInSessionOrChat() == true)
			{
				user->writeCommand(SESSION_REFUSED);
				user->writeMsg(string("The user you search for is in chat"));
				break;
			}
			openSession(user,usersMap[temp]); // else just open the session between them
			cout << BOLD(FGRN("A session has been created between the users: ")) << user->getUsername()<< BOLD(FGRN(" and ")) << temp << endl;
			break;

		case EXIT:
			serverExit(user);
			break;

		case SESSION_CLOSED:
			user->closeSession(true);
			break;

		case CHAT_ROOM_CREATE:
			chatRoomCreate(user);
			break;

		case CHAT_ROOM_CLOSE:
			chatRoomDelete(user);
			break;

		case CHAT_ROOM_USER_JOIN:
			chatRoomEnter(user);
			break;

		case CHAT_ROOM_USER_LEFT:
			user->disconnectFromChatRoom(false);
			break;

		case LIST_CONNECTED_USERS:
			getActiveUsers(user);
			break;

		case LIST_ROOMS:
			getRoomByUser(user);
		break;

		case LIST_CONNECTED_USERS_IN_ROOM:
			getRoomUsers(user);
			break;

		case LIST_USERS:
			getUsers(user);
			break;
		}
	}
}

/**
 * The method responsible to add user to he map
 */
bool ServerManager::userAdd(TCPSocket* socket, string userName)
{
	bool add = true;
	User* userToAdd = new User(userName, socket);

	usersMap.insert(pair<string,User*>(userName,userToAdd));
	cout << BOLD(FGRN("The user ")) <<  userName << BOLD(FGRN(" logged in")) << endl;

	return add;
}

/**
 * The method responsible to disconnect the client from the server and erase from the map
 */
void ServerManager::serverExit(User* user)
{
	cout << BOLD(FBLU("The User: "))<< user->getUsername() << BOLD(FBLU(" has disconnected from the server")) <<endl;
	usersMap.erase(user->getUsername());
}

/**
 * The method responsible to create a session between two peers
 */
void ServerManager::openSession(User* first, User* second) {

	second->connectBetweenUsers(first);
	first->connectBetweenUsers(second);

	second->writeCommand(SESSION_ESTABLISHED);
	second->writeMsg(first->getUsername());
	second->writeMsg(first->getIP());
	second->writeCommand(first->getPort());
	second->writeCommand(second->getPort());

	first->writeCommand(SESSION_ESTABLISHED);
	first->writeMsg(second->getUsername());
	first->writeMsg(second->getIP());
	first->writeCommand(second->getPort());
	first->writeCommand(first->getPort());
}

/**
 * The method responsible to create a chat room
 */
void ServerManager::chatRoomCreate(User* user)
{
	string temp;
	temp = user->readMsg();

	// Checking that the name does exist
	for (map<string,ChatRoom*>::iterator iter = chatRoomsMap.begin(); iter !=  chatRoomsMap.end();iter++)
	{
		if (iter->first == temp)
		{
			cout << "The room is already exist" << endl;
			user->writeCommand(CHAT_ROOM_CREATE_DENIED);
			return;
		}
	}

	// Add new chat room
	chatRoomsMap[temp] = new ChatRoom(user, temp);
	user->writeCommand(CHAT_ROOM_CREATE);
	cout << BOLD(FGRN("The room: ")) << temp << BOLD(FGRN(" has been created")) << endl;
}

/**
 * The method responsible to delete chat room and erase it from the map
 */
void ServerManager::chatRoomDelete(User* user)
{
	string temp;
	temp = user->readMsg();
	bool exist = false;

	for (map<string,ChatRoom*>::iterator iter = chatRoomsMap.begin(); iter !=  chatRoomsMap.end();iter++)
	{
		if (iter->first == temp)
		{
			exist = true;
			if(chatRoomsMap[temp]->getOwner()->getUsername() == user->getUsername())
			{
			    delete(chatRoomsMap[temp]);
				user->writeCommand(CHAT_ROOM_CLOSE);
				chatRoomsMap.erase(temp);
				cout << BOLD(FBLU("The chat room has been deleted")) << endl;
				return;
			}
		}
	}
	if (exist == true){
		user->writeCommand(CHAT_ROOM_CLOSE_DENIED);
	}
	else{
		user->writeCommand(CHAT_ROOM_NOT_EXIST);
	}
}

/**
 * The method responsible to enter a chat room
 */
void ServerManager::chatRoomEnter(User* user)
{
	string roomName = user->readMsg();
	bool exist = false;
	for (map<string,ChatRoom*>::iterator iter = chatRoomsMap.begin(); iter !=  chatRoomsMap.end();iter++)
	{
		if (iter->first == roomName)
		{
			exist = true;
		}
	}

	if (exist == false)
	{
		user->writeCommand(CHAT_ROOM_USER_JOIN_DENIED);
		user->writeMsg(string("The room is not exist"));
		return;
	}

	user->chatRoomConfirmation(chatRoomsMap[roomName]);
	if (chatRoomsMap[roomName]->userAdd(user) == true)
	{
		user->writeCommand(CHAT_ROOM_USER_JOIN);
		user->writeCommand(user->getPort());
	}
	else
	{
		user->writeCommand(CHAT_ROOM_USER_JOIN_DENIED);
		user->writeMsg(string("You are already logged in"));
	}
}


ServerManager::~ServerManager() {
	running = false;
	waitForThread();
}
