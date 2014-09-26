#include "ChatServlet.h"


ChatServlet::ChatServlet(void)
{
}


ChatServlet::~ChatServlet(void)
{
}

void ChatServlet::processWisper(Packet &packet,ServerResource* res,ServerNetwork* network)
{
	packet.wisperId;
    char content[] = "im server";
    network->response(content,packet.wisperId);
}
