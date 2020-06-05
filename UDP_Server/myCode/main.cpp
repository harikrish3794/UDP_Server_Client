// Standard (system) header files
#include <iostream>
#include <stdlib.h>


#include "UDP.h"
#include "UDPServer.h"

using namespace std;

// Main program
int main (void)
{
	cout << "UDP_Server has started." << endl << endl;

	// Startup Wincock
	UDP starter;
	starter.startWinsock();

	//Create an object of UDP_Server specifying (IPv4, UDP_Datagram, PortNumber)
	UDPServer UDP_Server(AF_INET, SOCK_DGRAM, 50003);

	//Create a socket
	UDP_Server.createSocket();

	//Bind socket to ip address address
	while(true)
	{
		int errBind = UDP_Server.server_create_bind();
			if(errBind == 1) continue;
			else break;
	}

	cout<<"Waiting to receive data..."<<endl<<endl;
	while(true)
		{
			//Data is received here
			if (UDP_Server.receiveData() == 1)
				break;
			//Display
			UDP_Server.displayData();
		}

	cout<<endl<<"Server Closed after receiving data 5 times"<<endl;

	//Close Socket
	closesocket(UDP_Server.getSOCKET());

	//Shutdown Winsock
	WSACleanup();

	return 0;
}
