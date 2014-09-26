#include "ServletManager.h"
#include "PlayerSession.h"
#include "ServerResource.h"

ServletManager::ServletManager(void)
{
    m_chat = new ChatServlet();
}


bool ServletManager::allotServlet(Packet& packet, ServerResource* res ,PlayerSession * session)
{
    switch (packet.packet_type) {

        case INIT_CONNECTION:
        {
            printf("server received init packet from client;: %s\n",packet.words);
            char content[] = "this is a system broadcast ,welcome to this world!\n";
            session->network()->broadcast(content);				
            break;
        }
        case BROAD_CAST:
        {
            printf("server received broad cast!%s\n" ,packet.words);
            //broadcast(packet.words,iter->first);
            break;
        }
        case WISPER:
        {
            //m_chat->processWisper(packet,res,network);
            break;
        }
        default:
        {
            printf("error in packet types\n");

            break;
        }
    }
    return true;
}

ServletManager::~ServletManager(void)
{
    if(m_chat != NULL)
    {
        delete m_chat;
        m_chat = NULL;
    }
}
