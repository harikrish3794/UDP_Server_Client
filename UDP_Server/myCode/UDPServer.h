/*
 * UDPServer.h
 *
 *  Created on: Jun 4, 2020
 *      Author: Hari Krishna Yelchuri
 */

#ifndef UDPSERVER_H_
#define UDPSERVER_H_

#include "UDP.h"

class UDPServer : public UDP
{
private:
	sockaddr_in client; // Use to hold the client information (port / ip address)
	int clientLength = sizeof(client); // The size of the client information
	char clientIp[256]; // Stores client IP as a string
	char buf[1024] = {0}; //Buffer to store received data
	int count = 0; //A variable for count of 5

public:
	UDPServer();
	
	//A parametrized constructor
	UDPServer(int m_ipType, int m_dataType, unsigned short m_port);
	
	//Create server structure and bind the socket to it
	int server_create_bind();
	
	//Function to receive data
	bool receiveData();
	
	//Function to display the received data
	void displayData();
};

#endif /* UDPSERVER_H_ */
