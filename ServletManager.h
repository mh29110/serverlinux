//#pragma once
#ifndef SERVLET_MANAGER_H
#define SERVLET_MANAGER_H
#include "ChatServlet.h"
class ServerNetwork;
class PlayerSession;
class ServerResource;
#include "NetworkData.h"
//class Servlet
//{
//public:
//    virtual ~Servlet(){}
//
//    virtual bool doRequest(Packet& packet, ServerResource* res ,ServerNetwork * newwork){}
//};


class ServletManager
{
public:
	ServletManager(void);
	~ServletManager(void);
	ChatServlet * m_chat;

    virtual bool  allotServlet(Packet& packet, ServerResource* res ,PlayerSession * session);
};

#endif //SERVLET_MANAGER_H
