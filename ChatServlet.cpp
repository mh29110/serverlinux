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

	network->response("im server",packet.wisperId);
}
