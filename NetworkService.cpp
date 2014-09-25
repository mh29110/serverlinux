#include "NetworkService.h"


int  NetworkService::sendMessage( SOCKET curSocket , char * message , int messageSize)
{
	return send(curSocket,message,messageSize,0);
}
int NetworkService::receiveMessage( SOCKET curSocket , char * buffer , int bufSize)
{
	return recv(curSocket, buffer, bufSize,0);
}
