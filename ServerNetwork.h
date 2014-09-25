#pragma once

#include "NetworkService.h"
#include <map>

#include "NetworkData.h"
#include "global.h"

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <unistd.h>
#include <string>
#include <string.h>
#include <stdio.h>
#include <arpa/inet.h>



using namespace std; 
#define DEFAULT_BUFLEN 512
#define DEFAULT_PORT 6881 
const int MAXHOSTNAME = 200;
const int MAXCONNECTION = 5;
const int MAXRECV = 512;

#define INVALID_SOCKET  (SOCKET)(~0)
#define SOCKET_ERROR            (-1)

class ServerNetwork
{
public:
	ServerNetwork(void);
    ~ServerNetwork(void);

    // Socket to listen for new connections
    SOCKET ListenSocket;

    // Socket to give to the clients
    SOCKET ClientSocket;

    // for error checking return values
    int iResult;

    // table to keep track of each client's socket
    std::map<unsigned int, SOCKET> sessions; 

	 // accept new connections
    bool acceptNewClient(SOCKET& id);

	 // receive incoming data
    int receiveData(unsigned int client_id, char * recvbuf);

	 void sendToAll(char * packets, int totalSize);

	 void broadcast(char* content);

	 void response(char* content,int wisperId);
private:
    sockaddr_in m_addr;
    
};

