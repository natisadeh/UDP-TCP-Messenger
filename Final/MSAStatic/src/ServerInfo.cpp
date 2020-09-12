/*
 * ServerInfo.cpp
 *
 *
 * Author: Nati & Eli
 */


#include "ServerInfo.h"
/**
 * The method responsible to print all the users in a session
 */
void ServerInfo::printSessions()
{
	std::map<string,User*>::iterator iter;

	if (usersMap.begin()==usersMap.end()){
		cout<< BOLD(FBLU("There are no opened sessions!")) <<endl;
	}
	else
	{
		cout << BOLD(FBLU("Current connected users in session are:")) << endl;
		string name;
		for (iter = usersMap.begin() ; iter != usersMap.end();iter++)
		{
			if(iter->second->isInSession() == true)
			{
				name = iter->first;
				cout << name << endl;
			}
		}
	}
}

/**
 * The method responsible to print the users from the text file (registered users)
 */
void ServerInfo::printUsers()
{
	cout << BOLD(FBLU("The registered users are:")) << endl;
	readFromFile(NULL);
}

/**
 * The method responsible to print all the active users in the application
 */
void ServerInfo::printActiveUsers()
{
	map<string,User*>::iterator iter;
	string userName;

	if (usersMap.begin() == usersMap.end())
	{
		cout << BOLD(FBLU("There are no connected users")) << endl;
		return;
	}

	cout<<"The Connected users are:"<<endl;
	for (iter = usersMap.begin(); iter != usersMap.end(); iter++)
	{
		userName = iter->first;
		cout << userName << endl;
	}
}

/**
 * The method responsible to print the users in a given room
 */
void ServerInfo::printUsersInSpecificRoom(string roomName)
{
	if (chatRoomsMap.find(roomName) == chatRoomsMap.end())
	{
		cout << BOLD(FBLU("The room ")) << roomName << BOLD(FBLU("has not found")) << endl;
		return;
	}
	cout<<"The current users in" << roomName << ":"<< endl;
	for (map<string,ChatRoom*>::iterator iter = chatRoomsMap.begin(); iter !=  chatRoomsMap.end();iter++)
	{
		if (roomName == iter->first){
			iter->second->ChatRoom::printUsers();
		}
	}

	if (chatRoomsMap.size() == 0)
		cout << "There are no users in this room"<< endl;
}

/**
 * The method responsible to check if a given user is active
 */
bool ServerInfo::isConnected(string username)
{
	if (usersMap.find(username) == usersMap.end())
		return false;
	return true;
}

/**
 * The method responsible to confirm rooms and send it to the printing method
 */
void ServerInfo::printRooms()
{
	if (chatRoomsMap.begin() != chatRoomsMap.end())
	{
		cout << BOLD(FBLU("Current active rooms:")) << endl;
		getRoom(NULL);
	}
	else
		cout << BOLD(FBLU("There are no opened rooms")) << endl;
}

/**
 * The method responsible to display room names (depends if the client or the server call it)
 */
void ServerInfo::getRoom(User * user)
{
	string roomName;
	for (map<string,ChatRoom*>::iterator iter = chatRoomsMap.begin(); iter !=  chatRoomsMap.end();iter++)
	{
		roomName = iter->first;
		if (user != NULL)
		{
			user->writeMsg(roomName); // send it back to the user who request it
		}
		else
		{
			cout << roomName << endl;
		}
	}
}

/**
 * The method responsible to display the room list (only if the user called it)
 */
void ServerInfo::getRoomByUser(User * user)
{
	user->writeCommand(LIST_ROOMS);
	user->writeCommand(chatRoomsMap.size());
	getRoom(user);
}


/**
 * The method responsible to display connected users
 */
void ServerInfo::getActiveUsers(User * user)
{
	user->writeCommand(LIST_CONNECTED_USERS);
	user->writeCommand(usersMap.size());

	map<string,User*>::iterator iter;
	string userName;

	for (iter = usersMap.begin() ; iter != usersMap.end();iter++)
	{
		userName = iter->first;
		user->writeMsg(userName);
	}
}

/**
 * The method responsible to display the connected users from a given room
 */
void ServerInfo::getRoomUsers(User * user)
{
	bool flag = false;
	bool nati = true;
	string chatRoomName = user->readMsg();
	int count = 0;

	for (map<string,ChatRoom*>::iterator iter = chatRoomsMap.begin(); iter !=  chatRoomsMap.end();iter++)
	{
		if (chatRoomName == iter->first   && chatRoomsMap.empty() == false)
		{
			for (map<string,User*>::iterator iter = usersMap.begin(); iter !=  usersMap.end();iter++)
			{
				if(iter->second->isInChatRoom() == true){
					break;
				}
				else
				{
					user->writeCommand(CHAT_ROOM_EMPTY);
					return;
				}
			}
			flag = true;
			user->writeCommand(LIST_CONNECTED_USERS_IN_ROOM);
			(iter)->second->userSendList(user);
			break;
		}
	}

	if (flag == false)
	{
		user->writeCommand(CHAT_ROOM_NOT_EXIST);
		cout << BOLD(FRED("The room is not exist")) << endl;
		return;
	}
}

/**
 * The method responsible to display the users in the text file
 */
void ServerInfo::getUsers(User * user)
{
	int numOfusers = fileCountUsers();

	user->writeCommand(LIST_USERS);
	user->writeCommand(numOfusers -1);

	if (user != NULL)
	{
		readFromFile(user);
	}
	else
	{
		readFromFile(NULL);
	}
}

/**
 * The method responsible to display the users from the text file
 */
void ServerInfo::readFromFile(User * user)
{
	string line;
	fstream loginFile; // stream class for both read and write files
	string userFromFile;
	loginFile.open(usersFile,ios::in|ios::out|ios::binary);
	if (loginFile.is_open())
	{
		while ( !loginFile.eof() )
		{
			getline (loginFile,line);
			userFromFile = line.substr(0, line.find(" "));
			if (user != NULL) // if the user is active
			{
				user->writeMsg(userFromFile); // printing the users from the text file to the client
			}
			else
			{
			  cout << userFromFile << endl; // print to the server
			}

		}
	loginFile.close();
	}
	else
	{
		cout << BOLD(FRED("Problem with open the file")) << endl;
	}
}

/**
 * Giving the numbers of users from the file (Users.txt)
 */
int ServerInfo::fileCountUsers(){
	string line;
	fstream loginFile;
	string userFromFile;
	int counter = 0;

	loginFile.open(usersFile,ios::in|ios::out|ios::binary);

	while ( !loginFile.eof() )
	{
	  getline (loginFile,line);
	  counter++;
	}
	loginFile.close();
	return counter;
}

