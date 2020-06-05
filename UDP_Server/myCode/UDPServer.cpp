/*
 * UDPServer.cpp
 *
 *  Created on: Jun 4, 2020
 *      Author: Hari Krishna Yelchuri
 */

#include "UDPServer.h"
#include <iostream>

using namespace std;

UDPServer::UDPServer()
{
}

UDPServer::UDPServer(int m_ipType, int m_dataType,  unsigned short m_port) : UDP(m_ipType, m_dataType, m_port)
{
}

int UDPServer::server_create_bind()
{
	// Create a server hint structure
	this->getServer().sin_addr.S_un.S_addr = ADDR_ANY; // Us any IP address available on the machine
	this->getServer().sin_family = this->getipType(); // Address format is IPv4
	this->getServer().sin_port = htons(this->getport()); // Convert from little to big endian

	// Try and bind the socket to the IP and port
	if (bind(this->getSOCKET(), (sockaddr*)&this->getServer(), sizeof(this->getServer())) == SOCKET_ERROR)
	{
		cout << "Can't bind socket! " << WSAGetLastError() << endl;
		return 1;
	}

	cout<<"Created socket and binded successfully"<<endl<<endl;
	return 0;
}

bool UDPServer::receiveData()
{

	ZeroMemory(&client, clientLength); // Clear the client structure
	ZeroMemory(buf, 1024); // Clear the receive buffer

	// Wait for message
	int bytesIn = recvfrom(this->getSOCKET(), buf, 1024, 0, (sockaddr*)&client, &clientLength);
	if (bytesIn == SOCKET_ERROR)
	{
		cout << "Error receiving from client " << WSAGetLastError() << endl;
	}
	else
	{	//To stop data reception after 5 successful receptions
		count++;
		if(count > 5)
			return 1;
	}
	return 0;
}

void UDPServer::displayData()
{
	// Display message and client info

	ZeroMemory(clientIp, 256);

	// Convert from byte array to chars
	inet_ntop(AF_INET, &client.sin_addr, clientIp, 256);

	// Display the message and from where
	cout << "Message recv from " << clientIp << " : " << buf << endl;
}
