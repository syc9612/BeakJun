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
    void listen();
};

void server::socket_create(){
    WSADATA wsaData; //WSADATA 클래스를 갖다 쓰네;
    WSAStartup(MAKEWORD(2,2), &wsaData);

    SOCKET hListen;
    hListen = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);

    SOCKADDR_IN tListenAddr = {};
    tListenAddr.sin_family = AF_INET;
    tListenAddr.sin_port = PORT;
    tListenAddr.sin_addr.s_addr = htonl(INADDR_ANY);

    bind(hListen, (SOCKADDR*)&tListenAddr, sizeof(tListenAddr));

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
void server::listen(){

}