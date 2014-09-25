#include "PlayerSession.h"

  
PlayerSession::PlayerSession(SOCKET sock,ServerResource* res,ServletManager* servs, ServerNetwork* network)
							 :m_sockId(sock)
{
	// id's to assign clients for our table

	m_res = res;
	m_servlets = servs;
	m_network = network;
}

void PlayerSession::processPacket(Packet packet)
{
	   switch (packet.packet_type) {

                case INIT_CONNECTION:
					printf("server received init packet from client;: %s\n",packet.words);
					m_network->broadcast("this is a system broadcast ,welcome to this world!\n");				
                    break;

                case BROAD_CAST:

                    printf("server received broad cast!%s\n" ,packet.words);
					//broadcast(packet.words,iter->first);
                    break;
				case WISPER:
					m_servlets->m_chat->processWisper(packet,m_res,m_network);
					break;
                default:

                    printf("error in packet types\n");

                    break;
            }
}


PlayerSession::~PlayerSession(void)
{
}
