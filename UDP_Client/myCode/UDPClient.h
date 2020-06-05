/*
 * UDPClient.h
 *
 *  Created on: Jun 4, 2020
 *      Author: Hari Krishna Yelchuri
 */

#ifndef UDPCLIENT_H_
#define UDPCLIENT_H_

#include "UDP.h"
#include <iostream>
#include <stdlib.h>

using namespace std;

class UDPClient : public UDP
{
private:
	//Data to be sent out
	string s = "DLR IS GREAT";
public:
	UDPClient();
	//Parametrized Constructor
	UDPClient(int m_ipType, int m_dataType, unsigned short m_port);

	//Fills server information
	void create_Server();

	//Sends out data
	void sendData();
};

#endif /* UDPCLIENT_H_ */
