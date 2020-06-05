/*
 * UDPClient.cpp
 *
 *  Created on: Jun 4, 2020
 *      Author: Hari Krishna Yelchuri
 */

#include "UDPClient.h"

UDPClient::UDPClient()
{
}

UDPClient::UDPClient(int m_ipType, int m_dataType,  unsigned short m_port) : UDP(m_ipType, m_dataType, m_port)
{
}

void UDPClient::create_Server()
{
	//Fills server details
	this->getServer().sin_family = AF_INET; // AF_INET = IPv4 addresses
	this->getServer().sin_port = htons(this->getport()); // Little to big endian conversion
	inet_pton(AF_INET, "127.0.0.1", &this->getServer().sin_addr); // Convert from string to byte array
}

void UDPClient::sendData()
{
	//Send data out
	int sendOk = sendto(this->getSOCKET(), s.c_str(), s.size() + 1, 0, (sockaddr*)&this->getServer(), sizeof(this->getServer()));

		if (sendOk == SOCKET_ERROR)
		{
			cout << "That didn't work! " << WSAGetLastError() << endl;
		}
}
