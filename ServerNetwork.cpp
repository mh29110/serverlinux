#include "ServerNetwork.h"
#include <memory.h>
#include <errno.h>
#include <stdio.h>

ServerNetwork::ServerNetwork(void)
{

    ListenSocket = INVALID_SOCKET;

    memset( &m_addr, 0 , sizeof(m_addr) ) ;

    
    ListenSocket = socket(AF_INET, SOCK_STREAM , 0) ;  
    if (ListenSocket == -1) {
       // printf("startup failed with error: \n");
       // exit(1);
        return;
    }
    int on = 1;
    if ( setsockopt ( ListenSocket, SOL_SOCKET, SO_REUSEADDR, ( const char* ) &on, sizeof ( on ) ) == -1 )
    {
              return ;
    }

    m_addr.sin_family = AF_INET;
    m_addr.sin_addr.s_addr = INADDR_ANY;
    m_addr.sin_port = htons(6881);

    iResult = bind( ListenSocket, (struct sockaddr * ) &m_addr , sizeof(m_addr) );

    if (iResult == -1) {
        printf("bind failed with error: %d\n", -1);
    //    exit(1);
        return ;
    }

    // start listening for new clients attempting to connect
    iResult = listen(ListenSocket, MAXCONNECTION);

    if (iResult == SOCKET_ERROR) {
        //exit(1);
        return;
    }
    
    printf("socket inited!\n");

}

// accept new connections
bool ServerNetwork::acceptNewClient(SOCKET & id)
{
    // if client waiting, accept the connection and save the socket
    id = accept(ListenSocket,NULL,NULL);

    if (id != -1) 
    {
        //disable nagle on the client's socket
        //char value = 1;
        //setsockopt( id, IPPROTO_TCP, TCP_NODELAY, &value, sizeof( value ) );

      
		ClientSocket = id;
        return true;
    }

    return false;
}


ServerNetwork::~ServerNetwork(void)
{
}

// receive incoming data
int ServerNetwork::receiveData(unsigned int client_id, char * recvbuf)
{
    if( sessions.find(client_id) != sessions.end() )
    {
		SOCKET currentSocket = sessions[client_id];
        iResult = NetworkService::receiveMessage(currentSocket, recvbuf, MAX_PACKET_SIZE);
        if (iResult == 0)
        {
            printf("Connection closed\n");
//            closesocket(currentSocket);
        }
        return iResult;
    }
    return 0;
} 

// send data to all clients
void ServerNetwork::sendToAll(char * packets, int totalSize)
{
    SOCKET currentSocket;
    std::map<unsigned int,  SOCKET>::iterator iter;
    int iSendResult;

    printf("send to all! \n");
    int c = 0;
    for (iter = sessions.begin(); iter != sessions.end(); iter++)
    {
		currentSocket = iter->second;
        iSendResult = NetworkService::sendMessage(currentSocket, packets, totalSize);
        printf("send to all! %d \n!" ,c);
        c++;

        if (iSendResult == SOCKET_ERROR) 
        {
            printf("send failed with error: %d\n", -1);
//            closesocket(currentSocket);
        }
    }
}
void ServerNetwork::broadcast(char* content)
{
	//send broadcast packet

	const unsigned int packet_size = sizeof(Packet);
	char packet_data[packet_size];

	Packet packet;
	packet.packet_type = BROAD_CAST;
	packet.wisperId = NetworkService::SystemId;
	strcpy(packet.words,content);

	packet.serialize(packet_data);
	sendToAll(packet_data,packet_size);
}

void ServerNetwork::response(char* content,int wisperId)
{
	//send response packet

	const unsigned int packet_size = sizeof(Packet);
	char packet_data[packet_size];

	Packet packet;
	packet.packet_type = BROAD_CAST;
	packet.wisperId = wisperId;
	strcpy(packet.words,content);

	packet.serialize(packet_data);


	 SOCKET currentSocket;
    std::map<unsigned int,  SOCKET>::iterator iter;
    int iSendResult;
	if( (iter = sessions.find(wisperId)) != sessions.end() )
    {
		currentSocket = iter->second;
        iSendResult = NetworkService::sendMessage(currentSocket, packet_data, packet_size);

        if (iSendResult == SOCKET_ERROR) 
        {
            printf("send failed with error: %d\n", -1);
            //closesocket(currentSocket);
        }
    }
}
