#pragma once
#include "NetworkData.h"
#include "ServerResource.h"
#include "ServerNetwork.h"

class ChatServlet
{
public:
	ChatServlet(void);
	~ChatServlet(void);
	void processWisper(Packet &packet,ServerResource*,ServerNetwork*);
};

