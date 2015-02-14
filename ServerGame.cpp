#include "ServerGame.h"
unsigned int ServerGame::client_id; 
#include "PlayerSession.h"
#include <stdio.h>

ServerGame::ServerGame(void)
{
    // id's to assign clients for our table
    client_id = 0;

    // set up the server network to listen 
    network = new ServerNetwork(); 

	//static data and DB connection 
	m_res = new ServerResource();

	m_servlets = new ServletManager();

    printf("server has been started\n"); 
}

void ServerGame::update() 
{
	SOCKET client_sock;
    // get new clients
    if(network->acceptNewClient(client_sock))
    {
        printf("client %d has been connected to the server\n",client_sock); 

		// insert new client into session id table
		PlayerSession * session = new PlayerSession(client_sock,m_res,m_servlets,network);
        network->sessions.insert( pair<unsigned int, SOCKET>(client_id, client_sock) );

		sessions.insert(	pair<unsigned int , PlayerSession*>(client_id , session)  );

        client_id++;
    }

	 receiveFromClients();
}

void ServerGame::receiveFromClients()
{
    Packet packet;

    // go through all clients
    std::map<unsigned int,  SOCKET>::iterator iter;

    for(iter = network->sessions.begin(); iter != network->sessions.end(); iter++)
    {
        // get data for that client
        int data_length = network->receiveData(iter->first, network_data);

        if (data_length <= 0) 
        {
            //no data recieved
            continue;
        }
        printf("data length = %d \n", data_length);

        int i = 0;
        while (i < (unsigned int)data_length) 
        {
            packet.deserialize(&(network_data[i]));
            i += sizeof(Packet);

            printf( " find the processer \n");

           if( sessions.find(iter->first) !=  sessions.end() )
			{
                printf("process packet! \n");
				sessions[iter->first]->processPacket(packet);
		    }
        }
    }
}

ServerGame::~ServerGame(void)
{
    delete  network ; 

    delete	m_res ;

    delete	m_servlets;

    //todo delete sessions //todo
}

