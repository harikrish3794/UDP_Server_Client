/*
 * UDP.cpp
 *
 *  Created on: Jun 4, 2020
 *      Author: Hari Krishna Yelchuri
 */

#include "UDP.h"
#include <iostream>

using namespace std;

UDP::UDP()
{
}

void UDP::startWinsock()
{
	WSADATA data;
	WORD version = MAKEWORD(2,2);

	int wsok = WSAStartup(version, &data);

	if(wsok != 0)
	{
		cout<<"Can't start Winsock!"<<wsok;
	}
}

UDP::UDP(int ipType, int dataType,  unsigned short port)
{
	this->m_ipType = ipType;
	this->m_dataType = dataType;
	this->m_port = port;
	this->m_socket = 0;
}

void UDP::createSocket()
{
	m_socket = socket(this->m_ipType, this->m_dataType, 0);
}

int UDP::getipType()
{
	return m_ipType;
}

SOCKET& UDP::getSOCKET()
{
	return m_socket;
}

sockaddr_in& UDP::getServer()
{
	return m_server;
}

int UDP::getport()
{
	return m_port;
}
