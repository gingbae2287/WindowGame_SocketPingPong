#pragma once
#include "define.h"
#include <thread>
#include <winsock2.h>
#include <iphlpapi.h>
#include <ws2tcpip.h>

#pragma comment(lib, "ws2_32.lib")

#define PORT 7777
#define PACKET_SIZE 1024
class NetworkManager
{
	SINGLETON(NetworkManager)
private:
	WSADATA wsaData;
	int iResult;

	SOCKET sock;
	SOCKADDR_IN sockAddr;
	SOCKET hListen;
	char buffer[PACKET_SIZE] = {};
private:
	NetworkManager();
	~NetworkManager();

public:
	bool isMaster;
	unsigned int viewID;

public:
	void Init();

	//host
	void CreateRoom();
	void WaitClient();

	//cient
	void JoinRoom(const char*);


};

