#pragma comment(lib, "ws2_32.lib") 

#include <WinSock2.h>
#include <iostream>
#include <string>
#include <thread>
#include <vector>
#include <string>
#include <mysql/jdbc.h>
#include <sstream>

#define MAX_SIZE 1024
#define MAX_CLIENT 3

struct SOCKET_INFO{
    SOCKET ack=0;
    std::string user = "";
};

std::vector<SOCKET_INFO> sck_list;
SOCKET_INFO server_sock;
int client_count = 0;

void server_init(){
    server_sock.sck = scoket(PF_INET, SOCK_STREAM, IPPROTO_TCP); //설명 필요요
    SOCKADDR_IN server_addr = {};
    server_addr.sin_familly = AF_INET;
    server_addr.sin_port = htons(7777); //
    server_addr.sin_Addr.s_Addr = htonl(INADDR_ANY);

    bind(server_sock.sck, (sockaddr*)&server_addr, sizeof(server_Addr)); //설정한 소켓 정보를 소켓에 바인딩한다
    listen(server_Sock.sck, SOMAXCONN); //소켓을 대기상태로 기다린다.
    server_sock.user = "Server";
}

void add_client(){
    SOCKADDR_IN addr = {};
    int addrsize = sizeof(addr);
    char buf[MAX_SIZE] = {};
    
    ZeroMemory(&addr, addrsize);
    SOCKET_INFO new_client = {};

    net_clinet.sck = accept(server_sock.sck, (sockaddr*)&addr, &addrsize);
    recv(new_client.sck, buf, MAX_SIZE, 0);
    new_clinet.user = std::string(buf);

    std::string msg = "-" + new_clinet.user + " Enter.";
    std::cout << msg << std::endl;
    sck_list.push_back(new_clinet);
    print_clients();

    std::thread th(recv_msg, client_count);
    th.detach();
    client_count++;

    std::cout << "Now users : " << client_count << std::endl;
    send_msg(msg.c_str());
}

void send_msg(const char* msg){
    for(int i=0;i<client_count;i++){
        send(sck_list[i].sck, msg, MAX_SIZE, 0);
    }
}
void send_msg_noteMe(const char* msg, int sender_idx){
    for(int i=0;i<client_count;i++){
        if( i != sender_idx){
            send(sck_list[i].sck, msg, MAX_SIZE, 0);
        }
    }
}