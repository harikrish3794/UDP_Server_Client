/*
 * UDP.h
 *
 *  Created on: Jun 4, 2020
 *      Author: Hari Krishna Yelchuri
 */

#ifndef UDP_H_
#define UDP_H_

#include <ws2tcpip.h>

class UDP
{
private:
	SOCKET m_socket; //The socket from which data is sent or received
	sockaddr_in m_server; //Server structure specifying the address, address format, port
	int m_ipType; //Specifies IPv4 or IPv6
	int m_dataType; //Specifies Communication Style
	unsigned short m_port; //Port number of operation

public:
	UDP();

	//Parametrized constructor for UDP
	UDP(int ipType, int dataType, unsigned short port);

	//Basic winsock starter
	void startWinsock();

	//Creates a socket with mentioned ip_type and protocol (TCP/UDP)
	void createSocket();

	//returns m_socket
	SOCKET& getSOCKET();

	//returns m_server
	sockaddr_in& getServer();

	//returns the type of protocol used
	int getipType();

	//returns the port number
	int getport();
};

#endif /* UDP_H_ */
