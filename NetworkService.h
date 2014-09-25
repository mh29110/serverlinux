#pragma once
#include "global.h"
#include <sys/types.h>
#include <sys/socket.h>
class NetworkService
{
public:
	static int sendMessage( SOCKET curSocket , char * message , int messageSize);
	static int receiveMessage( SOCKET curSocket , char * buffer , int bufSize);
	
	 static const int SystemId = -1;
};

