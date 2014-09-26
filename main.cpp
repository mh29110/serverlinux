// may need #include "stdafx.h" in visual studio
#include "ServerGame.h"
#include <iostream>
#include <set>

void serverLoop();

ServerGame * server;

int main()
{
	// initialize the server
	server = new ServerGame();
    serverLoop();
}
void serverLoop() 
{ 
    while(true) 
    {
        server->update();
    }
}
