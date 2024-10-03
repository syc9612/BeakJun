#include "EmailBook.h"
#include <iostream>

int main(){


    std::cout << "--------------" << std::endl;
    //case 함수 사용


    /*
    Error: Unable to perform this action because the process is running
    해결: 스택오버플로우에서 해답을 찾을 수 있었다. launch.json의 "externalConsole": true로 바꾸면, 외부 터미널이 열리면서 외부 터미널에 값을 입력할 수 있다.
    */
    int client;
   
    std::cout << "input the number of people" << std::endl;
    std::cin >> client;

    EmailBook* clients = { new EmailBook[client] };
    int index{ 0 };

    for(;;){
        while ( index < client){
            
        }
    }
}