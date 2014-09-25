#pragma once

#include "NetworkData.h"
//#include "ServerResource.h"
#include "ServletManager.h"
#include "ServerNetwork.h"
#include "global.h"
#include <stdio.h>
class ServerResource;

class PlayerSession
{

public:
	PlayerSession(SOCKET sock,ServerResource*,ServletManager* , ServerNetwork*);
	~PlayerSession(void);
	
	//process the packet from  specific socket client 
	void processPacket(Packet packet);
	


	SOCKET m_sockId ;
private:
	ServerResource* m_res;
	ServletManager* m_servlets;
	ServerNetwork* m_network;
};

