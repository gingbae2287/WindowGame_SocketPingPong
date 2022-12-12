#include "NetworkManager.h"
NetworkManager::NetworkManager()
:wsaData()
{

}

NetworkManager::~NetworkManager() {

}

void NetworkManager::Init()
{
    iResult = WSAStartup(MAKEWORD(2, 2), &wsaData);
    if (iResult != 0) {
        return;
    }
    isMaster = false;
    viewID = 0;
    
}

//====host func====

void NetworkManager::CreateRoom() {
    hListen = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);

    SOCKADDR_IN tListenAddr = {};
    tListenAddr.sin_family = AF_INET;
    tListenAddr.sin_port = htons(PORT);
    tListenAddr.sin_addr.s_addr = htonl(INADDR_ANY);

    bind(hListen, (SOCKADDR*)&tListenAddr, sizeof(tListenAddr));
    listen(hListen, SOMAXCONN); //SOMAXCONN 요청 가능한 최대 접속 승인수
    if (hListen == SOCKET_ERROR)
    {
        //closesocket(hListen);
        //WSACleanup();
        return (void) - 1;
    }

    isMaster = true;
    viewID = 1;


    

}
void NetworkManager::WaitClient() {
    int iClntSize = sizeof(sockAddr);

    sock = accept(hListen, (SOCKADDR*)&sockAddr, &iClntSize);
    if (sock == INVALID_SOCKET) {
        //accept error
        return;
    }
}

///=====Client func

void NetworkManager::JoinRoom(const char* ip) {
    sock = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);

    sockAddr.sin_family = AF_INET;
    sockAddr.sin_port = htons(PORT);
    sockAddr.sin_addr.s_addr = inet_addr(ip);
    while (1) if (!connect(sock, (SOCKADDR*)&sockAddr, sizeof(sockAddr))) break;
}