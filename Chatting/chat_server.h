#include <WinSock2.h>
#include <iostream>
#include <string>

#define PORT  4578
#define PACKET_SIZE  1024

class server{
    private:
    std::string ip_address = "127.0.0.1";

    public:
    void socket_create();
    void close();
    
};

void server::socket_create(){
    WSADATA wsaData; //WSADATA 클래스를 갖다 쓰네;
    WSAStartup(MAKEWORD(2,2), &wsaData);

    SOCKET hSocket;
    hSocket = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);

    SOCKADDR_IN tListenAddr = {};
    tListenAddr.sin_family = AF_INET;
    tListenAddr.sin_port = PORT;
    tListenAddr.sin_addr.s_addr = htonl(INADDR_ANY);

    bind(hSocket, (SOCKADDR*)&tListenAddr, sizeof(tListenAddr));
    listen(hSocket, SOMAXCONN);

    SOCKADDR_IN tClntAddr = {};
    int iClientSize = sizeof(tClntAddr);
    SOCKET hClient = accept(hSocket, (SOCKADDR*)&tClntAddr, &iClientSize); //소켓에서 들어오는 연결을 수락하는 함수.

    char cMsg[] = "Client Send";
    send(hSocket, cMsg, strlen(cMsg), 0);

    char cBuffer[PACKET_SIZE] = {};
    recv(hSocket, cBuffer, PACKET_SIZE, 0);
    printf("Recv MSG : %s\n", cBuffer);

    closesocket(hSocket);

    /*
    struct sockaddr_in {
    short sin_family;
    u_short sin_port;
    struct in_addr sin_addr;
    char sin_zero[8];
};
    */
}

void server::close(){
    WSACleanup();
}
