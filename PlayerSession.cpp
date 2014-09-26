#include "PlayerSession.h"

#include "ServerResource.h"
#include "ServletManager.h"
#include "ServerNetwork.h"
  
PlayerSession::PlayerSession(SOCKET sock,ServerResource* res,ServletManager* servs, ServerNetwork* network)
							 :m_sockId(sock)
{
	// id's to assign clients for our table

	m_res = res;
	m_servlets = servs;
	m_network = network;
}

void PlayerSession::processPacket(Packet& packet)
{
    m_servlets->allotServlet(packet , m_res , this);
	 }


PlayerSession::~PlayerSession(void)
{
}
