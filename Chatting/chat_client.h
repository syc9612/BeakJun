#include <string>
#include <stdio.h>
#include <winsock2.h>

#define PORT 4578
#define PACKET_SIZE 1024
#define SERVER_IP "172.30.1.55"
//https://easycode.tistory.com/19 참고

class client{
    private:
    std::string msg_content;
    std::string user_name;

    public:
    int connection();  
};

int client::connection(){
    WSADATA wsaData;
    WSAStartup(MAKEWORD(2,2), &wsaData);

    SOCKET hSocket;
    hSocket = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);

    SOCKADDR_IN tAddr = {};
    tAddr.sin_family = AF_INET;
    tAddr.sin_port = htons(PORT);
    tAddr.sin_addr.s_addr = inet_addr(SERVER_IP);

    connect(hSocket, (SOCKADDR*)&tAddr, sizeof(tAddr));

    char cMsg[] = "Client Send";
    send(hSocket, cMsg, strlen(cMsg), 0);

    char cBuffer[PACKET_SIZE] = {};
    recv(hSocket, cBuffer, PACKET_SIZE, 0);
    printf("Recv Msg : %s\n", cBuffer);

    closesocket(hSocket);

    WSACleanup();
    return 0;
}
