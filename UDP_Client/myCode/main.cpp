// Standard (system) header files
#include <iostream>
#include <stdlib.h>

//User includes
#include "UDP.h"
#include "UDPClient.h"

using namespace std;

// Main program
int main (void)
{
	// Startup Wincock
	UDP starter;
	starter.startWinsock();

	//Create client object
	UDPClient UDP_Client(AF_INET, SOCK_DGRAM, 50003);

	//Create socket for UDP
	UDP_Client.createSocket();

	//Create
	UDP_Client.create_Server();

	//Sends "DLR IS GREAT" 10 times
	for(int count = 0; count<10 ; count++)
		{
			UDP_Client.sendData();
		}

	//Close Socket
	closesocket(UDP_Client.getSOCKET());

	//Shutdown Winsock
	WSACleanup();

	return 0;
}
