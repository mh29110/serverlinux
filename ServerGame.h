#pragma once
#include "ServerNetwork.h"
#include "NetworkData.h"
#include "ServerResource.h"
#include "ServletManager.h"
#include "PlayerSession.h"
#include "global.h"
class ServerGame
{
public:

    ServerGame(void);
    ~ServerGame(void);

    void update();
	void receiveFromClients();

private:

   // IDs for the clients connecting for table in ServerNetwork 
    static unsigned int client_id;

   // The ServerNetwork object 
    ServerNetwork* network;

	 char network_data[MAX_PACKET_SIZE];

	 ServerResource * m_res;

	 ServletManager* m_servlets;

	 
	   // table to keep track of each client's socket
	std::map<unsigned int, PlayerSession*> sessions; 
};

