/*
 * TCPMessengerProtocol.h
 *
 *
 *
 */
#ifndef TCPMESSENGERPROTOCOL_H_
#define TCPMESSENGERPROTOCOL_H_

#define MSNGR_PORT 5214

#define CLOSE_SESSION_WITH_PEER 	      1
#define OPEN_SESSION_WITH_PEER 		      2
#define EXIT						      3
#define SEND_MSG_TO_PEER			      4
#define SESSION_REFUSED				      5
#define SESSION_ESTABLISHED		       	  6
#define SESSION_CLOSED				      7
#define SESSION_CREATE				      8

#define LOGIN_REQUEST				      20
#define LOGIN_REQUEST_APPROVED            21
#define LOGIN_REQUEST_DENIED              22

#define REGISTRATION_REQUEST	          23
#define REGISTRATION_REQUEST_APPROVED     24
#define REGISTRATION_REQUEST_DENIED		  25

#define CHAT_ROOM_CREATE                  30
#define CHAT_ROOM_CREATE_DENIED           31
#define CHAT_ROOM_USER_LEFT               32
#define CHAT_ROOM_USER_JOIN               33
#define CHAT_ROOM_USER_JOIN_DENIED        34
#define CHAT_ROOM_UPDATE                  35
#define CHAT_ROOM_CLOSE                   36
#define CHAT_ROOM_CLOSE_DENIED            37
#define CHAT_ROOM_NOT_EXIST               38
#define CHAT_ROOM_EMPTY                   39


#define LIST_USERS                        40
#define LIST_CONNECTED_USERS              41
#define LIST_ROOMS                        42
#define LIST_CONNECTED_USERS_IN_ROOM      43


#endif /* TCPMESSENGERPROTOCOL_H_ */
